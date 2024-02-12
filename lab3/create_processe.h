#ifndef SUM_H_1
#define SUM_H_1

#include <sys/stat.h>
#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "unistd.h"
#include "sys/wait.h"
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <signal.h>

int create_processe(){
    pid_t pid = fork();

    if(pid == -1){
        
        perror("Сreating a process");
        exit(-1);
    }
    return pid;
};
#endif