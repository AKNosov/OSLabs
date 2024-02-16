#include "generator.h"
void print(int128_t num)
{
    printf("DEC: \n");
    char array[DEC_SIZE + 1];
    int i;
    for (i = 0; i < DEC_SIZE; ++i) {
        array[i] = '0'; 
    }
    array[DEC_SIZE] = TERMINAL_NULL;
    for (i = DEC_SIZE - 1; num > 0; --i) {
        array[i] = (int) (num % 10) + '0'; //представляем в коде аски и заполняем массив с конца
        num /= 10;
    }
        printf("%s\n", &array[i + 1]); 
}

int number_checker(char *s)
{
    return (*s >= '0' && *s <= '9'); 
}

int hexdexconvert(char *s) {
    if(*s == 'a')
        return 10;
    if(*s == 'b')
        return 11;
    if(*s == 'c')
        return 12;
    if(*s == 'd')
        return 13;
    if(*s == 'e')
        return 14;
    if(*s == 'f')
        return 15;
    return 0;
}

int128_t to128bit(char *s) 
{
    int128_t num = 0;
    while (*s) {
        if (number_checker(s))
            num = num * 16 + (*s - '0');
        else {
            int b = hexdexconvert(s);
            num = num * 16 + b;
        }
        ++s; 
    }
    return num;
}