#ifndef _ARBOLBB_H
#define _ARBOLBB_H

typedef struct nodeT {
    int key;
    char name[50];
    struct nodeT *l;
    struct nodeT *r;
} nodeT;

typedef nodeT* Tree;

void crear_abb(Tree *a);
void insert_abb(Tree *a, int key, const char *name);
void search_abb(Tree a, int key);
void preorden(Tree r);
void remove_abb(Tree *a);

#endif
