#include <bits/stdc++.h>
using namespace std;

#define N 16
#define SIZE 256

vector<int> ICache(SIZE);
vector<int> DCache(SIZE);
vector<int> RF(N);

int PC = 0;

int total_inst = 0;
int cycles = 0;
int stalls = 0;
int data_stall = 0;


bool halt_seen = false;
bool halt_done = false;

// pipeline registers
struct IFID { int instr; bool valid=false; } ifid;
struct IDEX { int op,rd,rs1,rs2,imm,A,B; bool valid=false; } idex;
struct EXMEM { int op,rd,alu,B; bool cond; bool valid=false; } exmem;
struct MEMWB { int op,rd,alu,LMD; bool valid=false; } memwb;

// sign extend
int sext(int v,int b){ int m=1<<(b-1); return (v^m)-m; }

// FIXED LOAD (with error check)
void load(string f, vector<int>& v, int limit){
    ifstream file(f);

    if(!file){
        cout << "ERROR: Cannot open file " << f << endl;
        exit(1);
    }

    string s; int i=0;
    while(getline(file,s) && i<limit){
        if(s.empty()) continue;
        v[i++] = stoi(s,0,16);
    }
}

// RAW hazard
bool RAW(int r1,int r2){
    if(idex.valid && idex.rd!=0 && (idex.rd==r1||idex.rd==r2)) 
        return true;
    if(exmem.valid && exmem.rd!=0 && (exmem.rd==r1||exmem.rd==r2)) 
        return true;
    if(memwb.valid && memwb.rd!=0 && (memwb.rd==r1||memwb.rd==r2)) 
      return true;
    return false;
}

// IF
void IF_stage(bool stall){
    if(stall || halt_seen) return;
    if(PC >= SIZE-1) return;

    int ins = (ICache[PC]<<8)|ICache[PC+1];
    ifid.instr = ins;
    ifid.valid = true;

    PC += 2;
}

// ID
bool ID_stage(){
    if(!ifid.valid) return false;

    int ins = ifid.instr;//not hexadecimal

    int op  = (ins>>12)&0xF;
    int rd  = (ins>>8)&0xF;
    int rs1 = (ins>>4)&0xF;
    int last= ins&0xF;

    int rs2 = last;
    int imm = (op==8||op==9)? last : sext(last,4);

    if(RAW(rs1,rs2)){
        stalls++; data_stall++;
        idex.valid=false;
        return true;
    }
    if(op == 12) {   // ST opcode
    idex = {op, rd, rs1, rs2, imm, RF[rs1], RF[rd], true};
    }
    else {
    idex = {op, rd, rs1, rs2, imm, RF[rs1], RF[rs2], true};
    }

    ifid.valid=false;

    if(op==15) halt_seen=true;

    return false;
}

// EX
void EX_stage(){
    if(!idex.valid) return;

    exmem.op=idex.op;
    exmem.rd=idex.rd;
    exmem.B=idex.B;//Help in store inst 

    switch(idex.op){
        case 0: exmem.alu=idex.A+idex.B; break;
        case 1: exmem.alu=idex.A-idex.B; break;
       
    }

    exmem.valid=true;
    idex.valid=false;
}

// MEM
void MEM_stage(){
    if(!exmem.valid) return;

    memwb.op=exmem.op;
    memwb.rd=exmem.rd;
    memwb.alu=exmem.alu;
   
    if(exmem.op==11) memwb.LMD=DCache[exmem.alu];
    else if(exmem.op==12) DCache[exmem.alu]=exmem.B;

    memwb.valid=true;
    exmem.valid=false;
}

// WB
void WB_stage(){
    if(!memwb.valid) return;

    if(memwb.op==15){
        halt_done=true;
        total_inst++;
        memwb.valid=false;
        return;
    }
    cout<<"Output "<<memwb.alu<<"\n";

    if(memwb.op<=10) RF[memwb.rd]=memwb.alu;
    else if(memwb.op==11) RF[memwb.rd]=memwb.LMD;

    total_inst++;
    memwb.valid=false;
}
void save(){
    ofstream f("output/Output.txt");

    f << "Total Instructions: " << total_inst << "\n";
    f << "Cycles: " << cycles << "\n";
    f << "CPI: " << (float)cycles / max(1, total_inst) << "\n";
    f << "Total Stalls: " << stalls << "\n";
    f << "Data Stalls: " << data_stall << "\n";

    ofstream d("output/DCache.txt");
    for(int i=0;i<SIZE;i++)
        d << hex << setw(2) << setfill('0') << DCache[i] << "\n";
}
// MAIN
int main(){

    load("Icache.txt",ICache,SIZE);
    load("Dcache.txt",DCache,SIZE);
    load("RF.txt",RF,N);

    while(true){
        cycles++;

        WB_stage();
        MEM_stage();
        EX_stage();
        bool d = ID_stage();
        IF_stage(d);

        if(halt_done &&
           !ifid.valid &&
           !idex.valid &&
           !exmem.valid &&
           !memwb.valid)
            break;

        if(cycles > 10000){
            cout<<"input issue or no HLT\n";
            break;
        }
   }

save();
    cout<<"DONE\n";
}
