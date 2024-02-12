#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    fp = fopen("file.txt", "w"); // открываем файл для записи

    if (fp == NULL) { // проверяем, что файл успешно открыт
        printf("Ошибка открытия файла\n");
        exit(1);
    }

    srand(time(NULL)); // инициализируем генератор случайных чисел

    for (int i = 0; i < 100; i++) { // записываем 10 случайных чисел в файл
        unsigned char bytes[16]; // массив для хранения 128-битного числа
        for (int j = 0; j < 16; j++) {
            bytes[j] = rand() % 256; // генерируем случайный байт
        }
        fprintf(fp, "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n",
                bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7],
                bytes[8], bytes[9], bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15]);
    }

    fclose(fp); // закрываем файл
    return 0;
}