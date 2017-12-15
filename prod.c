
#include <stdio.h>
#include "shared.h"

int main (int argc, char *argv[]) {
    if(argc<2) return 1;
    P(sem_create(PROD, NULL));
    int shmid;
    do {
        shmid = shmget(SEM_FIFO, sizeof(FIFO), 0666);
    } while (shmid == -1);
    FIFO *fifo = shmat(shmid, NULL, 0);
    
    P(sem_create(SEM_FIFO, NULL));
    fifo->buffer[(fifo->pEcriture++) % SIZE_BUFFER] = argv[1][0];
    V(sem_create(SEM_FIFO, NULL));
    
    
    V(sem_create(CONSO, NULL));

}