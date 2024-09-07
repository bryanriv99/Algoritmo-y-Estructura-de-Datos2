#include<stdio.h>
#include<stdlib.h>
#include "Cola.h"

void create(squeue *q){
    q->head = 0;
    q->tail = -1;
}

int next(int index){
    return (index + 1) % size;

}

int is_empty(squeue *q){
    if(q->tail == -1){
        return true;
    }else{
        return false;
    }
}

int is_full(squeue *q){
    if(q->head == next(q->tail) && q->tail != -1){
        return true;
    }else{
        return false;
    }
}

void enqueue(squeue *q, element x){
    if(is_full(q)){
        printf("Queue is full\n");
    }else{
        q->array[next(q->tail)] = x;
        q->tail = next(q->tail);
    }
}

int dequeue(squeue *q){
    element x;
    if(is_empty(q)){
        printf("Queue is empty\n");
        return -1;
    }else {
        x = q->array[q->head];
        if(q->head == q->tail){
            q->head = 0;
            q->tail = -1;
        }else{
            q->head = next(q->head);
        }
        return x;
    }
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
    if (i == 10){
        printf("Cola llena\n");
    }
}