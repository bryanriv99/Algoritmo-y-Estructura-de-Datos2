#include <stdio.h>
#include <stdlib.h>
#include "DStack.h"

//jazmin montserrath velazquez trinidad
//Rivera Plascencia Bryan

void equilibrado(Node_DS **);

void main() {
    char *A;
    A = (char*)malloc(100*sizeof(char));
    printf("Introduce una cadena: ");
    scanf("%s", A);
    printf("\n");
    Node_DS *P1;
    create_DS(&P1);
    char a;
    int i;
    for(i = 0; A[i] != '\0'; i++){
        a = A[i];
        push_DS(&P1, a);
    }
    equilibrado(&P1);
}

void equilibrado(Node_DS **P1){
    int contPA = 0;
    int contPC = 0;
    int contCA = 0;
    int contCC = 0;
    int contLA = 0;
    int contLC = 0;
    int P,C,L;
    element e;
    while(!is_Empty_DS(*P1)){
        e = pop_DS(P1);
        if(e == '('){
            contPA++;
        } else if(e == ')'){
            contPC++;
        } else if(e == '['){
            contCA++;
        } else if(e == ']'){
            contCC++;
        } else if(e == '{'){
            contLA++;
        } else if(e == '}'){
            contLC++;
        }
    }
    if(contPA == contPC && contCA == contCC && contLA == contLC){
        printf("La cadena es equilibrada\n");
    }else{
        printf("La cadena no es equilibrada\n");
        
        if(contPA > contPC){
            P = contPA - contPC;
            printf("Faltan %d )\n", P);
        }else if(contPA < contPC){
            P = contPC - contPA;
            printf("Faltan %d (\n", P);
        }

        if(contCA > contCC){
            C = contCA - contCC;
            printf("Faltan %d ]\n", C);
        }else if(contCA < contCC){
            C = contCC - contCA;
            printf("Faltan %d [\n", C);
        }

        if(contLA > contLC){
            L = contLA - contLC;
            printf("Faltan %d }\n", L);
        }else if(contLA < contLC){
            L = contLC - contLA;
            printf("Faltan %d {\n", L);
        }
    }
}