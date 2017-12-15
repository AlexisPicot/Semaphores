

#include <stdio.h>
#include "shared.h"

void main(void) {


    P(sem_create(CONSO, NULL));
    int shmid;
    do {
        shmid = shmget(SEM_FIFO, sizeof(FIFO), 0666);
    } while (shmid == -1);
    FIFO *fifo = shmat(shmid, NULL, 0);

    P(sem_create(SEM_FIFO, NULL));
    printf("%c", fifo->buffer[(fifo->pLecture++) % SIZE_BUFFER]);
    V(sem_create(SEM_FIFO, NULL));

    //On en est au même "point" et on a lu tout le buffer
    if(fifo->pEcriture==fifo->pLecture && fifo->pEcriture%SIZE_BUFFER==0)
        P(sem_create(PROD, NULL));
    V(sem_create(PROD, NULL));

}

