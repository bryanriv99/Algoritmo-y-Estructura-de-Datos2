#include<stdio.h>
#include<stdlib.h>
#include "Cola.h"

void mostrar(squeue *);
void Copiar(squeue *, squeue *);
void llenaCola(squeue *);

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

void Copiar(squeue *q, squeue *q2){
    int i;
    if(is_empty(q)){
        printf("Es vacia\n");
    }else{
        for(i = q->head; i != q->tail; i = next(i)){
            enqueue(q2, q->array[i]);
        }
        enqueue(q2, q->array[q->tail]);
    }
}

void mostrar(squeue *q){
    int i;
    if(is_empty(q)){
        printf("Es vacia\n");
    }else{
        for(i = q->head; i != q->tail; i = next(i)){
            printf("%d ", q->array[i]);
        }
        printf("%d\n", q->array[q->tail]);
    }
}

void llenaCola(squeue *q){
    int i = 0;
    int x;
    printf("Desea ingresar un elemento a la cola 1:SI 0:NO\n");
    scanf("%d", &x);
    while(x == 1 && i < 10){
        printf("Ingrese el elemento: ");
        scanf("%d", &x);
        enqueue(q, x);
        i++;
        printf("Desea ingresar un elemento a la cola 1:SI 0:NO\n");
        scanf("%d", &x);
    }
}