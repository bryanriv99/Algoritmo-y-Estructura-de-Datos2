#include <stdio.h>
#include <stdlib.h>
#include "Palindromo.h"
#include <ctype.h>

void palindromo(squeue *, sstack *);

void main(){
    char A[50];
    printf("Ingrese la palabra: ");
    scanf("%s", A);
    printf("\n");
    
    sstack pila;
    createss(&pila);
    squeue cola;
    create(&cola);

    char b;
    for(int i = 0; A[i] != '\0'; i++){
        b = tolower(A[i]);
        enqueue(&cola, b);
        pushs(&pila, b);
    }
    palindromo(&cola, &pila);
}

void palindromo(squeue *q, sstack *s){
    char a, b;
    int a1,b1;
    while(!isemptys(s) && !is_empty(q)){
        a = dequeue(q);
        b = pops(s);
        if (a != b){
            printf("\nNo es palindromo\n");
            return;
        }
    }
    a1 = is_empty(q);
    b1 = isemptys(s);
    if(a1 == 0 && b1 == 0){
        printf("\nEs palindromo\n");
    }
    if(a1 == 1 && b1 == 1){
        printf("\nEs palindromo\n");
    }
}