#ifndef MYLIBRARY1
#define MYLIBRARY1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float E(int);

float sum_of_series(int x);


#endif

double power(double base, int exponent) {
        double result = 1.0;
    
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    
    return result;
}

float E(int x)
{
    
    return power(1 + 1.0 / x, x);
}

float sum_of_series(int x)
{
    float sum = 1.0 ;
    float factorial = 1.0;
    
    for (int n = 1; n <= x; ++n) {
        factorial *= n;
        sum += 1.0 / factorial;
    }
    
    return sum;
}