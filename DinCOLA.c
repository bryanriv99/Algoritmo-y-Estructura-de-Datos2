#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct nodeDQ{
    element e;
    struct nodeDQ *next;
}nodeDQ;

typedef struct Dqueue{
    nodeDQ *head;
    nodeDQ *tail;
}Dqueue;

void createDQ(Dqueue *dq){
    dq->head = NULL;
    dq->tail = NULL;
}

int isEmpty(Dqueue *dq){
    if(dq->head == NULL){
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Dqueue *dq, element e){
    nodeDQ *newNode = (nodeDQ*)malloc(sizeof(nodeDQ));
    newNode->e = e;
    newNode->next = NULL;
    if(isEmpty(dq)){
        dq->head = newNode;
    } else {
        dq->tail->next = newNode;
    }
    dq->tail = newNode;
}

element dequeue(Dqueue *dq){
    if(isEmpty(dq)){
        printf("Empty\n");
    } else {
        nodeDQ *temp = dq->head;
        dq->head = dq->head->next;
        free(temp);
    }
}

