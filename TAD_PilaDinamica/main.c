#include <stdio.h>
#include "DStack.h"

//jazmin montserrath velazquez trinidad
//Rivera Plascencia Bryan

void copyStack(Node_DS *, Node_DS **);
void Suma(Node_DS *, Node_DS *, Node_DS **);

void main() {
    Node_DS *P1, *P2, *P3, *P4, *P5;
    
    create_DS(&P1);
    create_DS(&P2);
    create_DS(&P3);
    create_DS(&P4);
    create_DS(&P5);
    //ejericio 1
    llenarPila(&P1);
    copyStack(P1, &P2); 
    printDS(P2);
    //ejercicio 2
    printf("\n--------------------------------\n"); 
    llenarPila(&P3);
    printf("\n\n");
    llenarPila(&P4);
    Suma(P3, P4, &P5);
    printDS(P5);
    
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

void Suma(Node_DS *P1, Node_DS *P2, Node_DS **P3) {
    if (is_Empty_DS(P1) || is_Empty_DS(P2)) {
        printf("Al menos una de las pilas está vacía\n");
        return;
    }

    Node_DS *aux = NULL; 

    while (!is_Empty_DS(P1) || !is_Empty_DS(P2) || !is_Empty_DS(aux)) {
        element e1 = 0, e2 = 0, auxi = 0;
        
        if (!is_Empty_DS(P1))
            e1 = pop_DS(&P1);
        
        if (!is_Empty_DS(P2))
            e2 = pop_DS(&P2);
        
        if (!is_Empty_DS(aux))
            auxi = pop_DS(&aux);
        
        element suma = e1 + e2 + auxi;
        
        if (suma > 9) {
            push_DS(&aux, 1); 
            suma -= 10;
        }
        
        push_DS(P3, suma);
    }
}
