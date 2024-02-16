#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <inttypes.h>
#include <string.h>
#define DEC_SIZE 40
#define NUMBER_SIZE 32
#define FILE_SIZE 100
#define TERMINAL_NULL '\0'
typedef unsigned __int128 int128_t;
char *file_name = "file.txt";





void generate()
{
    int fd = open(file_name, O_RDWR| O_CREAT, 0666);
    char array[NUMBER_SIZE];
    srand(time(NULL)); 
    for (int i = 0; i < FILE_SIZE; ++i) {
        for (int i = 0; i < NUMBER_SIZE; ++i) {
            if (((int) rand()) % 2 == 0) {
                array[i] = '0' + (((int) rand()) % 10);
            } else {
                array[i] = 'A' + (((int) rand()) % 6);
            }
        }
        write(fd, &array, NUMBER_SIZE);
        write(fd, "\n", 1); //пишем в файле перевод строки
    }
    close(fd);
}
