#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


int main(){
    int check;
    void *current_lib;
    int arg, arg1, arg2;


    while(scanf("%d", &check) != EOF){
        if (check != 1 && check != 2){
            printf("You can only enter 1, 2 or 0\n");
            return 1;
        }
        else if(check == 1){
            printf("Your choice: prime count\n Please, enter 2 numbers: ");
            current_lib = dlopen("./lib1.so", RTLD_LAZY);
            if (!current_lib) {
             printf("Library loading error\n");
             return 1;
            }
            float (*naive_prime_count)(float, float) = dlsym(current_lib, "naive_prime_count"); 
            if (!naive_prime_count) {
                printf("Could not find function\n");
                return 1;
            }
            float (*eratosphene_prime_count)(float, float) = dlsym(current_lib, "eratosphene_prime_count"); 
            if (!eratosphene_prime_count) {
                printf("Could not find function\n");
                return 1;
            }
            scanf("%d %d", &arg1, &arg2);
            if (arg2<arg1) {
                printf("Second number should be bigger!\n");
                return 1;
            }
            printf("Naive implement: %f\n", naive_prime_count(arg1, arg2));
            printf("Eratosthenes method: %f\n", eratosphene_prime_count(arg1, arg2));
        }

        else if(check == 2){
            printf("Your choice: calculate Euler's number\n Please, enter 1 number: ");
            current_lib = dlopen("./lib2.so", RTLD_LAZY);
            if (!current_lib) {
             printf("Library loading error\n");
             return 1;
            }
            float (*E)(float) = dlsym(current_lib, "E"); 
            if (!E) {
                printf("Could not find function\n");
                return 1;
            }
            float (*sum_of_series)(float) = dlsym(current_lib, "sum_of_series"); 
            if (!sum_of_series) {
                printf("Could not find function\n");
                return 1;
            }
            scanf("%d", &arg);
            if (arg <= 0) {
                printf("Number should be bigger than 0!\n");
                return 1;
            }
            printf("(1 + 1 / x) ^ x method: %f\n", E(arg));
            printf("Sum of series method: %f\n", sum_of_series(arg));
        }   
        dlclose(current_lib); 
        return 0;
    }
}