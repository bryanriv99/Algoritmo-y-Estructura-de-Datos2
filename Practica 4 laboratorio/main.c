#include<stdio.h>
#include<stdlib.h>
#include "Cola.h"



void main(){
    squeue q, q2;
    int i;
    create(&q);
    create(&q2);
    llenaCola(&q);
    printf("Original:");
    mostrar(&q);
    printf("\n");
    Copiar(&q, &q2);
    printf("Copia:");
    mostrar(&q2);
}

