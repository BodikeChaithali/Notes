#include <bits/stdc++.h>
using namespace std;

#define N 16
#define SIZE 256

vector<int> ICache(SIZE);
vector<int> DCache(SIZE);
vector<int> RF(N);

int arithmetic=0, logical=0, memory=0, control=0;

int PC = 0;
int total_inst = 0;
int cycles = 0;
int stalls = 0;
int data_stall = 0;
int control_stall = 0;
int control_freeze = 0;

bool halt_seen = false;
bool halt_done = false;

// pipeline registers
struct IFID { int instr; bool valid=false; } ifid;
struct IDEX { int op,rd,rs1,rs2,imm,A,B; bool valid=false; } idex;
struct EXMEM { int op,rd,alu,B; bool valid=false; } exmem;
struct MEMWB { int op,rd,alu,LMD; bool valid=false; } memwb;

// sign extend
int sext(int v,int b){ int m=1<<(b-1); return (v^m)-m; }

// load file
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
    if(idex.valid && idex.rd!=0 && (idex.rd==r1||idex.rd==r2)) return true;
    if(exmem.valid && exmem.rd!=0 && (exmem.rd==r1||exmem.rd==r2)) return true;
    if(memwb.valid && memwb.rd!=0 && (memwb.rd==r1||memwb.rd==r2)) return true;
    return false;
}

// IF
void IF_stage(bool stall){
    if(control_freeze > 0){
        control_freeze--;
        return;
    }

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

    int ins = ifid.instr;

    int op  = (ins>>12)&0xF;
    int rd  = (ins>>8)&0xF;
    int rs1 = (ins>>4)&0xF;
    int last= ins&0xF;

    int rs2 = last;

    int imm;
    if(op == 10) imm = ins & 0xFF;
    else if(op==8 || op==9) imm = last;
    else imm = sext(last,4);

    // FIXED RAW SOURCES
    int r1 = rs1, r2 = rs2;

    if(op == 3){ r1 = rd; r2 = 0; }         // INC
    else if(op == 7){ r1 = rs1; r2 = 0; }   // NOT
    else if(op == 10){ r1 = 0; r2 = 0; }    // LI
    else if(op == 12){ r1 = rs1; r2 = rd; } // ST
    else if(op == 13){ r1 = 0; r2 = 0; }    // JMP
    else if(op == 14){ r1 = rd; r2 = 0; }   // BEQZ

    if(RAW(r1,r2)){
        stalls++;
        data_stall++;
        idex.valid=false;
        return true;
    }

    // Read registers
    int A,B;

    if(op == 3){ A = RF[rd]; B = 0; }           // INC
    else if(op == 7){ A = RF[rs1]; B = 0; }     // NOT
    else if(op == 10){ A = 0; B = 0; }          // LI
    else if(op == 12){ A = RF[rs1]; B = RF[rd]; } // ST
    else if(op == 13){ A = PC; B = 0; }         // JMP
    else if(op == 14){ A = PC; B = RF[rd]; }    // BEQZ
    else { A = RF[rs1]; B = RF[rs2]; }

    idex = {op, rd, rs1, rs2, imm, A, B, true};

    ifid.valid=false;

    if(op==15) halt_seen=true;

    // CONTROL HAZARD
    if(op == 13 || op == 14){
        control_freeze = 2;
        stalls += 2;
        control_stall += 2;
    }

    return false;
}

// EX
void EX_stage(){
    if(!idex.valid) return;

    exmem.op=idex.op;
    exmem.rd=idex.rd;
    exmem.B=idex.B;

    switch(idex.op){
        case 0: exmem.alu=idex.A+idex.B; break;
        case 1: exmem.alu=idex.A-idex.B; break;
        case 2: exmem.alu=idex.A*idex.B; break;
        case 3: exmem.alu=idex.A+1; break;

        case 4: exmem.alu=idex.A & idex.B; break;
        case 5: exmem.alu=idex.A | idex.B; break;
        case 6: exmem.alu=idex.A ^ idex.B; break;
        case 7: exmem.alu=~idex.A; break;

        case 8: exmem.alu=idex.A << idex.imm; break;
        case 9: exmem.alu=idex.A >> idex.imm; break;

        case 10: exmem.alu=idex.imm; break;

        case 11:
        case 12:
            exmem.alu=idex.A + idex.imm;
            break;

        case 13: // JMP
            PC = idex.A + idex.imm*2;
            break;

        case 14: // BEQZ
            if(idex.B == 0){
                PC = idex.A + idex.imm*2;
            }
            break;
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

    if(memwb.op<=3) arithmetic++;
    else if(memwb.op<=7) logical++;
    else if(memwb.op<=12) memory++;
    else control++;

    if(memwb.op==15){
        halt_done=true;
        total_inst++;
        memwb.valid=false;
        return;
    }

    if(memwb.op <= 9 || memwb.op == 10)
        RF[memwb.rd] = memwb.alu;
    else if(memwb.op == 11)
        RF[memwb.rd] = memwb.LMD;

    RF[0] = 0;

    total_inst++;
    memwb.valid=false;
}

// save output
void save(){
    ofstream f("output/Output.txt");

    f << "Total Instructions: " << total_inst << "\n";
    f << "Arithmetic: " << arithmetic << "\n";
    f << "Logical: " << logical << "\n";
    f << "Memory: " << memory << "\n";
    f << "Control: " << control << "\n";
    f << "CPI: " << (float)cycles / max(1, total_inst) << "\n";
    f << "Total Stalls: " << stalls << "\n";

    ofstream d("output/DCache.txt");
    for(int i=0;i<SIZE;i++)
        d << hex << setw(2) << setfill('0') << DCache[i] << "\n";
}

// MAIN
int main(){

    load("input/Icache.txt",ICache,SIZE);
    load("input/Dcache.txt",DCache,SIZE);
    load("input/RF.txt",RF,N);

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
