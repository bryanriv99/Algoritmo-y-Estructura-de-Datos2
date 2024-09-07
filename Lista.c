#include <stdio.h>
#define element int


typedef struct NodeL{
    element e;
    struct NodeL*next;
}nodeL;

typedef struct lista{
    nodeL *first;
}lista;

void createL(lista *li){
    li -> first = NULL;
}

void insertAtFirst(lista *li, element e){
    nodeL *new = (nodeL*)malloc(sizeof(nodeL));
    new -> e = e;
    new -> next = li -> first;
    li -> first = new;
}

void insertaralfinal(lista *li, element e){
    nodeL *new = (nodeL*)malloc(sizeof(nodeL));
    new -> e = e;
    new -> next = NULL;
    if(li -> first == NULL){
        li -> first = new;
    }else{
        nodeL *aux = li -> first;
        while(aux -> next != NULL){
            aux = aux -> next;
        }
        aux -> next = new;
    }
}

void eliminaralprincipio(lista *li){
    if(li -> first != NULL){
        nodeL *aux = li -> first;
        li -> first = aux -> next;
        free(aux);
    }
}

void eliminaralfinal(lista *li){
    if(li -> first != NULL){
        nodeL *aux = li -> first;
        nodeL *aux2 = NULL;
        while(aux -> next != NULL){
            aux2 = aux;
            aux = aux -> next;
        }
        if(aux2 == NULL){
            li -> first = NULL;
        }else{
            aux2 -> next = NULL;
        }
        free(aux);
    }
}

void eliminarlista(lista *li){
    while(li -> first != NULL){
        nodeL *aux = li -> first;
        li -> first = aux -> next;
        free(aux);
    }
}

void isEmpty(lista *li){
    if(li -> first == NULL){
        printf("La lista esta vacia\n");
    }else{
        printf("La lista no esta vacia\n");
    }
}

void buscarelemento(lista *li, element e){
    nodeL *aux = li -> first;
    int i = 0;
    while(aux != NULL){
        if(aux -> e == e){
            printf("El elemento %d se encuentra en la posicion %d\n", e, i);
            return;
        }
        aux = aux -> next;
        i++;
    }
    printf("El elemento %d no se encuentra en la lista\n", e);
}

nodeL* buscarElemento(lista *li, element e){
    nodeL *aux = li -> first;
    while(aux != NULL){
        if(aux -> e == e){
            return aux;
        }
        aux = aux -> next;
    }
    return NULL;
}

void main(){
    lista l;
    createL(&l);
}

