//
// Created by alexis.picot on 30/11/17.
//
#include <stdio.h>
#include "shared.h"

int main() {
    int idMem;
    //On crée une case en mémoire paratgée, si elle existe déjà on la recrée
    if ((idMem = shmget(SEM_FIFO, sizeof(FIFO), IPC_CREAT | IPC_EXCL | 0666)) == -1) {
        shmctl(shmget(SEM_FIFO, sizeof(FIFO), 0666), IPC_RMID, 0);
        if ((idMem = shmget(SEM_FIFO, sizeof(FIFO), IPC_CREAT | IPC_EXCL | 0666)) == -1) {
            perror("Echec de semget");
            exit(1);
        }
    }
    //On lie la case mémoire à une instance locale de FIFO
    FIFO *fifo = shmat(idMem, NULL, 0);
    printf("memoire partagee: cle:%d, ID: %d\n", SEM_FIFO, idMem);


    sem_create(PROD, SIZE_BUFFER);
    sem_create(CONSO, 0);


}
