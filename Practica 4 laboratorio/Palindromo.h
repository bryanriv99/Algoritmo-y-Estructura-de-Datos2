#ifndef _palin_
#define _palin_
#define size 50
typedef char element;
#define true 1
#define false 0

typedef struct Queue{
    int head;
    int tail;
    element array[size];
} squeue;

typedef struct Stack {
    element array[size];
    int top;
} sstack;

void create(squeue *q);

int next(int index);

int is_empty(squeue *q);

int is_full(squeue *q);

void enqueue(squeue *q, element x);

int dequeue(squeue *q);

void mostrar(squeue *q);
void Copiar(squeue *q, squeue *q2);
void llenaCola(squeue *q);

void createss(sstack *s);

int isemptys(sstack *s);

int isfulls(sstack *s);

void pushs(sstack *s, element e);

int pops(sstack *s);

void mostrarPil(sstack *s);
#endifls