#include "generator.h"
#include "128bit.h"
struct Command {
    int memory;
    int number_of_threads;
};

struct Params {
    long long num_count;
    int128_t localsum;
    off_t start_pos; //старт.позиция - откуда мы начинаем считывать число с файла
    long long thread_count_controller; //сколько чисел в 1 потоке
};

void initialization(struct Params *ptr, struct Command *command, long long num_count)
{
    ptr[0].num_count = num_count; //массив из thread_num элементов
    ptr[0].localsum = 0;
    ptr[0].start_pos = 0; //текущее число
    ptr[0].thread_count_controller = (num_count / command->number_of_threads); //сколько чисел пойдет в i-тый поток
    for (int i = 1; i < command->number_of_threads; ++i) {
        ptr[i].num_count = num_count;
        ptr[i].localsum = 0;
        ptr[i].start_pos = i * (ptr[i - 1].thread_count_controller * (NUMBER_SIZE + 1)); //стартовая позиция инкрементируется на кол-во чисел в строке
        ptr[i].thread_count_controller = ptr[i-1].thread_count_controller; //в каждый поток кладем конкретное значение 
    }
    ptr[command->number_of_threads - 1].thread_count_controller += num_count % command->number_of_threads; //если остались числа, кладем в последний поток остаток
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

    lseek(fd, ptr->start_pos, SEEK_SET); //несклько потоков, каждый поток со своего места в файле будет считывать
    for (int i = 0; i < ptr->thread_count_controller; ++i)
    {
        read(fd, array, NUMBER_SIZE);
        array[NUMBER_SIZE] = TERMINAL_NULL; 
        int128_t s;
        s = to128bit(array); //переводим буфер в 128битное десят. число
        s /= ptr->num_count;
        ptr->localsum += s;
        read(fd, &c, 1); //считываем один символ из строки
    }
    close(fd);
    return 0; 
}

int main(int argc, char* argv[])
{
    struct Command command;
    parse_command_line(argc, argv, &command); //получаем количество аргументов в argv, argv - массив из строк
    if (command.number_of_threads * sizeof(struct Params) + command.number_of_threads * sizeof(pthread_t) > command.memory) {
        fprintf(stderr, "%s\n", "Too much threads for this amount of memory");
        exit(EXIT_FAILURE);
    }
    pthread_t *thread_id = (pthread_t*)malloc(command.number_of_threads * sizeof(pthread_t)); //выделяем память под массив потоков
    struct Params *params = (struct Params*)malloc(command.number_of_threads * sizeof(struct Params)); //выделяем память под массив параметров
    generate();
    int fd = open(file_name, O_RDWR| O_CREAT, 0666);
    long long size = lseek(fd, 0, SEEK_END); //переместились в конец файла 
    close(fd);
    long long num_count = size / (NUMBER_SIZE + 1); //подсчитываем количество цифр 
    initialization(params, &command, num_count); //проинициализировали массив параметров
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