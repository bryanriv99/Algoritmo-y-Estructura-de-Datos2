#include <stdio.h>
#include <stdlib.h>
#define element int

typedef struct nodeT{
    element e;
    struct nodeT *l;
    struct nodeT *r;
}nodeT;

typedef nodeT * Tree;

void insertar(Tree *r, Tree le, Tree ri, element ele){
    Tree new = (Tree)malloc(sizeof(nodeT));
    new->e = ele;
    new->l = le;
    new->r = ri;
    *r = new;

}

void preorden(Tree r){
    if(r != NULL){
        printf("%d ", r->e);
        preorden(r->l);
        preorden(r->r);
    }
}

void enorden(Tree r){
    if(r != NULL){
        enorden(r->l);
        printf("%d ", r->e);
        enorden(r->r);
    }
}

void postorden(Tree r){
    if(r != NULL){
        postorden(r->l);
        postorden(r->r);
        printf("%d ", r->e);
    }
}

void remove(Tree *r){
    if(*r != NULL){
        remove(&(*r)->l);
        remove(&(*r)->r);
        free(*r);
    }
}

void main(){
    
}