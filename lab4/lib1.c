
#ifndef MYLIBRARY2
#define MYLIBRARY2
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int naive_prime_count(int, int);

int eratosphene_prime_count(int, int);

#endif

int naive_prime_count(int A, int B)
{
    int counter = 0;

    for (int i = A; i <= B; ++i) {
        if (i == 0 || i == 1) {
            continue;
        }

        int count_divider = 0;
        for (int j = 2; j <= i; ++j) {
            if (i % j == 0) {
                ++count_divider;
            }
        }

        if (count_divider <= 1) {
            ++counter;
        }
    }

    return counter;
}

int eratosphene_prime_count(int A, int B)
{

    bool is_prime[B + 1];
    for (int i = 0; i <= B; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= B; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= B; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int counter = 0;
    for (int i = A; i <= B; ++i) {
        if (is_prime[i]) {
            ++counter;
        }
    }

    return counter;
}