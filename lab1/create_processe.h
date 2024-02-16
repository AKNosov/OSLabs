
#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "unistd.h"
#include "sys/wait.h"

int create_processe(){

    pid_t pid = fork();

    if(pid == -1){
        
        perror("Сreating a process");
        exit(-1);
    }
    return pid;
}
