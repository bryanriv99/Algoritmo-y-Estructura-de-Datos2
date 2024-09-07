#include<stdio.h>
#include<stdlib.h>
#include "Cola.h"

//funciones

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
    }else{
        x = q->array[q->head];
        q->head = next(q->head);
        return x;
    }
}

