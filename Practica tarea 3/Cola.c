#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

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

void enqueue(Dqueue *dq, Cliente e){
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

Cliente dequeue(Dqueue *dq){
    Cliente e;
    if(isEmpty(dq)){
        printf("Empty\n");
    } else {
        nodeDQ *temp = dq->head;
        e = temp->e; 
        dq->head = dq->head->next;
        free(temp);
    }
    return e; 
}