#include <stdio.h>
#include <stdlib.h>
#include "lib1.c"
#include "lib2.c"

int main(){
        int check;
    while(scanf("%d", &check) != EOF){
        if (check != 1 && check != 2){
            printf("You can only enter 1, 2 or 0\n");
            return 1;
        }
        else if(check == 1){
            printf("Your choice: prime count\n Please, enter 2 numbers: ");
            float arg1, arg2;
            scanf("%f %f", &arg1, &arg2);
            if (arg2<arg1) {
                printf("Second number should be bigger!\n");
                return 1;
            }
            printf("Naive implement: %d\n", naive_prime_count(arg1, arg2));
            printf("Eratosthenes method: %d\n", eratosphene_prime_count(arg1, arg2));
        }
        else if(check == 2){
            printf("Your choice: calculate Euler's number\n Please, enter 1 number: ");
            float arg;
            scanf("%f", &arg);
            if (arg <= 0) {
                printf("Number should be bigger than 0!\n");
                return 1;
            }
            printf("(1 + 1 / x) ^ x method: %f\n", E(arg));
            printf("Sum of series method: %f\n", sum_of_series(arg));
        }
    }
    return 0;
}