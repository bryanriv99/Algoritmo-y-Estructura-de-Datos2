#include <stdio.h>
#include <stdlib.h>
#include "DStack.h"

void create_DS(Node_DS **ds){
    *ds=NULL;
}

void push_DS(Node_DS **ds,element e){
	Node_DS *new;
	new=(Node_DS*)malloc(sizeof(Node_DS));
	new->e=e;
	new->next=*ds;
	*ds=new;
}

int is_Empty_DS(Node_DS *ds){
	if (ds==NULL)
		return 1;
	else 
		return 0;
}

element pop_DS(Node_DS **ds){
	Node_DS *node_aux;
	element elem_aux;

	if(is_Empty_DS(*ds)){
	printf("\nERROR DE UNDERFLOW\n");
	} else {
		node_aux=*ds;
		*ds=node_aux->next;
		elem_aux=node_aux->e;
		free(node_aux);
		return elem_aux;
	}
}


void printDS2(Node_DS *ds){
	Node_DS *aux;

	aux=ds;

	while(aux!=NULL){
		printf("%d",aux->e);
		aux=aux->next;

	}
}


void deleteDS(Node_DS **ds) {
    element e;

    while (!is_Empty_DS(*ds)) {
        e = pop_DS(ds); 
        printf("Elemento eliminado: %d\n", e);
    }
}

void printDS(Node_DS *ds) {
    Node_DS *aux;

    aux = ds;

    while (aux != NULL) {
        printf("%d ", aux->e);
        aux = aux->next;
    }
    printf("\n");
}

void llenarPila(Node_DS **P){
	printf("Desea agregar un elemento a la pila? 1=Si, 0=No\n");
	int n;
	scanf("%d",&n);
	while(n!=0){
		element e;
		printf("Ingrese el elemento a agregar: ");
		scanf("%d",&e);
		push_DS(P,e);
		printf("Desea agregar un elemento a la pila? 1=Si, 0=No\n");
		scanf("%d",&n);
	}
}

void copyStack(Node_DS *P1, Node_DS **P2) { 
    if (is_Empty_DS(P1)) {
        printf("La pila esta vacia\n");
        return; 
    }
    Node_DS *aux = NULL; 
    element e;
    while (!is_Empty_DS(P1)) {
        e = pop_DS(&P1); 
        push_DS(&aux, e); 
    }
    while(!is_Empty_DS(aux)){
        e = pop_DS(&aux);
        push_DS(P2, e); 
    }
}