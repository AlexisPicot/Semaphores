//
// Created by alexis.picot on 30/11/17.
//

#ifndef SEMAPHORES_SHARED_H
#define SEMAPHORES_SHARED_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdbool.h>
#include "djikstra.h"

#define SIZE_BUFFER      8
#define PROD    4
#define CONSO     5
#define SEM_FIFO        6
typedef struct {
    int     pEcriture;
    int     pLecture;
    char    buffer[SIZE_BUFFER];
} FIFO;




#endif //SEMAPHORES_SHARED_H
