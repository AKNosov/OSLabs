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
        write(fd, "\n", 1); 
    }
    close(fd);
}



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
        array[i] = (int) (num % 10) + '0'; 
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


struct Command {
    int memory;
    int number_of_threads;
};

struct Params {
    long long num_count;
    int128_t localsum;
    off_t start_pos; 
    long long thread_count_controller; 
};

void initialization(struct Params *ptr, struct Command *command, long long num_count)
{
    ptr[0].num_count = num_count; 
    ptr[0].localsum = 0;
    ptr[0].start_pos = 0; 
    ptr[0].thread_count_controller = (num_count / command->number_of_threads);
    for (int i = 1; i < command->number_of_threads; ++i) {
        ptr[i].num_count = num_count;
        ptr[i].localsum = 0;
        ptr[i].start_pos = i * (ptr[i - 1].thread_count_controller * (NUMBER_SIZE + 1)); 
        ptr[i].thread_count_controller = ptr[i-1].thread_count_controller; 
    }
    ptr[command->number_of_threads - 1].thread_count_controller += num_count % command->number_of_threads; 
}

void parse_command_line(int argc, char* argv[], struct Command *command) 
{
    if (argc != 3) {
        fprintf(stderr, "%s\n","Usage: ThreadsNumber, Memory");
        exit(EXIT_FAILURE);
    }
    command->number_of_threads = atoi(argv[1]);
    command->memory = atoi(argv[2]);
}

void *thread_function(void *a)
{
    struct Params *ptr = (struct Params*)a;
    char array[NUMBER_SIZE + 1];
    char c;
    int fd = open(file_name, O_RDWR| O_CREAT, 0666);

    lseek(fd, ptr->start_pos, SEEK_SET); 
    for (int i = 0; i < ptr->thread_count_controller; ++i)
    {
        read(fd, array, NUMBER_SIZE);
        array[NUMBER_SIZE] = TERMINAL_NULL; 
        int128_t s;
        s = to128bit(array); 
        s /= ptr->num_count;
        ptr->localsum += s;
        read(fd, &c, 1); 
    }
    close(fd);
    return 0; 
}

int main(int argc, char* argv[])
{
    struct Command command;
    parse_command_line(argc, argv, &command); 
    if (command.number_of_threads * sizeof(struct Params) + command.number_of_threads * sizeof(pthread_t) > command.memory) {
        fprintf(stderr, "%s\n", "Too much threads for this amount of memory");
        exit(EXIT_FAILURE);
    }
    pthread_t *thread_id = (pthread_t*)malloc(command.number_of_threads * sizeof(pthread_t)); 
    struct Params *params = (struct Params*)malloc(command.number_of_threads * sizeof(struct Params)); 
    generate();
    int fd = open(file_name, O_RDWR| O_CREAT, 0666);
    long long size = lseek(fd, 0, SEEK_END); 
    close(fd);
    long long num_count = size / (NUMBER_SIZE + 1); 
    initialization(params, &command, num_count); 
    for (int i = 0; i < command.number_of_threads; ++i) {
        pthread_create(&thread_id[i], NULL, thread_function, (void *) &params[i]);
    }
    for (int j = 0; j < command.number_of_threads; ++j) {
        pthread_join(thread_id[j], NULL); 
    }
    int128_t res = 0;
    for (int i = 0; i < command.number_of_threads; ++i) {
        res += params[i].localsum;
    }
    print(res);
    free(thread_id);
    free(params);
    return 0;
}