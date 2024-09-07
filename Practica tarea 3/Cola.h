#ifndef _Dqueue_
#define _Dqueue_
typedef int element;

typedef struct{
    int asunto;
    int identificador;
}Cliente;

typedef struct nodeDQ{
    Cliente e;
    struct nodeDQ *next;
}nodeDQ;

typedef struct Dqueue{
    nodeDQ *head;
    nodeDQ *tail;
}Dqueue;

void createDQ(Dqueue *dq);

int isEmpty(Dqueue *dq);

void enqueue(Dqueue *dq, Cliente e);

Cliente dequeue(Dqueue *dq);

#endif