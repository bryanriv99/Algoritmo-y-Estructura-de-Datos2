#ifndef _SQUEUE
#define _SQUEUE
#define size 10
typedef int element;
#define true 1
#define false 0

typedef struct Queue{
    int head;
    int tail;
    element array[size];
} squeue;

void create(squeue *q);

int next(int index);

int is_empty(squeue *q);

int is_full(squeue *q);

void enqueue(squeue *q, element x);

int dequeue(squeue *q);

void mostrar(squeue *q);
void Copiar(squeue *q, squeue *q2);
void llenaCola(squeue *q);


#endif