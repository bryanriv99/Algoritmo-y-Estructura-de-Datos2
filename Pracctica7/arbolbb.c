#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolbb.h"

void crear_abb(Tree *a){
    *a = NULL;
}

void insert_abb(Tree *a, int key, const char *name){
    if(*a == NULL){
        Tree new_node = (Tree)malloc(sizeof(nodeT));
        new_node->key = key;
        strcpy(new_node->name, name);
        new_node->l = new_node->r = NULL;
        *a = new_node;
    } else if(key < (*a)->key){
        insert_abb(&(*a)->l, key, name);
    } else {
        insert_abb(&(*a)->r, key, name);
    }
}

void search_abb(Tree a, int key){
    if(a == NULL){
        printf("No se encontro el elemento %d\n", key);
    } else if(key == a->key){
        printf("Se encontro el elemento %d: %s\n", a->key, a->name);
    } else if(key < a->key){
        search_abb(a->l, key);
    } else {
        search_abb(a->r, key);
    }
}

void preorden(Tree r){
    if(r != NULL){
        printf("Clave: %d, Nombre: %s\n", r->key, r->name);
        preorden(r->l);
        preorden(r->r);
    }
}

void remove_abb(Tree *a){
    if(*a != NULL){
        remove_abb(&(*a)->l);
        remove_abb(&(*a)->r);
        free(*a);
        *a = NULL;
    }
}
