

#include <stdio.h>
#include "djikstra.h"
#include "shared.h"


int main() {
    sem_delete(sem_create(PROD, NULL));
    sem_delete(sem_create(CONSO, NULL));
    int idMem ;
    if((idMem = shmget(SEM_FIFO, sizeof(FIFO), 0666)) != -1) {
        shmctl(idMem, IPC_RMID, 0);
        if (shmget(SEM_FIFO, sizeof(FIFO), 0666) == -1)
            printf("memoire partagee supprimee: cle: %d, ID: %d \n", SEM_FIFO, idMem);
    }else{
        puts("Case introuvable !");
    }

    sem_delete(sem_create(SEM_FIFO, NULL));

}