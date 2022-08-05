#include <stdio.h>
#include <stdlib.h>//for exit()
#define _CRT_SECURE_NO_WARNINGS//to disable scanf() unsafe warnings

int main() {
    int div_count[10] = {0};
    int num = 0;//1 000 000 000 is max so int is suitable
    scanf("%d", &num);
    //special cases:
    if (num==0){
        printf("%d", 10);
        exit(0);
    }
    else if (num==1){
        printf("%d", 1);
        exit(0);
    }
    //common:
    else{
        for(int i = 9; i > 1; i--){
            while (num % i == 0){
                div_count[i]++;//array counts number of dividers from 9 to 2
                num = num / i;
            }
        }
    }

    if (num!=1){//if num isn't equal to 1 after dividing then there's a two-digit(or more) prime number in the divisors
        printf("%d", -1);
        exit(0);
    }
    else{
        for(int i = 2; i < 10; i++){
            while (div_count[i]>0){
                printf("%d", i);
                div_count[i]--;
            }
        }
    }
    return 0;
}
