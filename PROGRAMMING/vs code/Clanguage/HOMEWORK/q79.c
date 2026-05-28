#include<stdio.h>

int main(){
    int target=50;
    int days=0;
    int daily_increase=4;
    int current_amount=0;
    int daily_decrease=3;
    for(int i=0;;i++){
        days++;
        current_amount += daily_increase;
        if(current_amount >= target){
            break;
        }
        current_amount -= daily_decrease;
    }
    printf("Days required to reach at least %d units: %d\n", target, days);
    return 0;
}