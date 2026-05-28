#include<stdio.h>
//current bill generating
void main () {
   long servo,pre,cur,units;
   char name[30];
   float amt;
   printf("Enter serial no.:");scanf("%ld",&servo);
   printf("Enter owner name:");scanf("%s",name);
   printf("Enter previous month reading:"); scanf("%ld",&pre);
   current:
   printf("Enter current month reading:"); scanf("%ld",&cur);
   units=cur-pre;
   if(cur<pre) {puts("\aCheck current moth reading!!");goto current;}
   if(units<=50) amt=units*1.45;
   else if(units<=100) amt=50*1.45+(units-50)*2.80;
   else if(units<=200) amt=50*1.45+50*2.80+(units-100)*3.05;
   else if(units<=300) amt=50*1.45+50*2.80+100*3.05+(units-200)*4.75;
   else if(units<=500) amt=50*1.45+50*2.80+100*3.05+200*4.75+(units-400)*6.00;
   else amt=50*1.45+50*2.80+100*3.05+100*4.75+200*6.00+(units-500)*6.24;
   if(amt<50)amt=50;   
   printf("Your current bill is %f\n",amt);   
}
