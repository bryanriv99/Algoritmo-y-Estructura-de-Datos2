#include<stdio.h>
#include<stdlib.h>
typedef int element;

typedef struct nodeDL{
    struct nodeDL *prev;
    struct nodeDL *next;
    element e;
}nodeDL;

typedef struct DList{
    nodeDL *first;
    nodeDL *last;
}Dlist;

void createDL(Dlist *l){
    l->first = NULL;
    l->last = NULL;
}

int isEmpty(Dlist l){
    if(l.first == NULL && l.last == NULL){
        return 1;
    }else{
        return 0;
    }
}

void insertFirst(Dlist *l, element e){
    nodeDL *n = (nodeDL*)malloc(sizeof(nodeDL));
    n->e = e;
    n->prev = NULL;
    n->next = l->first;
    if(isEmpty(*l)){
        l->last = n;
    }else{
        l->first->prev = n;
    }
    l->first = n;
}

void insertLast(Dlist *l, element e){
    nodeDL *n = (nodeDL*)malloc(sizeof(nodeDL));
    n->e = e;
    n->next = NULL;
    n->prev = l->last;
    if(isEmpty(*l)){
        l->first = n;
    }else{
        l->last->next = n;
    }
    l->last = n;
}

element deleteFirst(Dlist *l){
    nodeDL *aux = l->first;
    element e1;
    if(isEmpty(*l)){
        printf("Lista vacia\n");
        return;
    }
    e1 = l->first->e;
    l->first = l->first->next;
    if(l->first == NULL){
        l->last = NULL;
    }else{
        l->first->prev = NULL;
    }
    free(aux);
    return e1;
}

nodeDL *searchElement(Dlist l, element e){
    nodeDL *aux = l.first;
    while(aux != NULL){
        if(aux->e == e){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

element deleteLast(Dlist *l){
    nodeDL *aux = l->last;
    element e1;
    if(isEmpty(*l)){
        printf("Lista vacia\n");
        return;
    }
    e1 = l->last->e;
    l->last = l->last->prev;
    if(l->last == NULL){
        l->first = NULL;
    }else{
        l->last->next = NULL;
    }
    free(aux);
    return e1;
}

nodeDL *searchElementi(Dlist l, int i){
    nodeDL *aux = l.first;
    int cont = 0;
    while(aux != NULL){
        if(cont == i){
            return aux;
        }
        cont++;
        aux = aux->next;
    }
    return NULL;
}

void insertAfterElementi(Dlist l, element e, int i){
    nodeDL *aux = searchElementi(l,i);
    nodeDL *n = (nodeDL*)malloc(sizeof(nodeDL));
    n->e = e;
    n->next = aux->next;
    n->prev = aux;
    aux->next = n;
    if(n->next != NULL){
        n->next->prev = n;
    }
}

void deleteDL(Dlist *l){
    nodeDL *aux = l->first;
    while(aux != NULL){
        l->first = l->first->next;
        free(aux);
        aux = l->first;
    }
    l->last = NULL;
}

element deleteElementi(Dlist *l, int i){
    nodeDL *aux = l->first;
    element e1;
    if(isEmpty(*l)){
        printf("Lista vacia\n");
        return;
    }

    nodeDL * aux2 = searchElementi(*l,i);

    if(aux2 == aux){
        e1 = deleteFirst(l);
    }else if (aux2->next == NULL){
        e1 = deleteLast(l);
    }else{
        e1 = aux2->e;
        aux = aux2;
        aux2 = aux2->next;
        aux = aux2->prev;
        aux->next = aux2;
        aux2->prev = aux;
        free(aux2->prev);
    }
    return e1;
}

void mostrar(Dlist l){
    nodeDL *aux = l.first;
    while(aux != NULL){
        printf("%d ", aux->e);
        aux = aux->next;
    }
    printf("\n");
}

void main(){
    Dlist l;
    createDL(&l);
    insertFirst(&l, 1);
    insertFirst(&l, 2);
    mostrar(l);
}