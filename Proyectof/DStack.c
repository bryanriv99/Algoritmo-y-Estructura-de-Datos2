#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "DStack.h"

void create_DS(Node_DS **ds) {
    *ds = NULL;
}

void pushD(Node_DS **pila, int disco) {
    Node_DS *new = (Node_DS *) malloc(sizeof(Node_DS));

    if (*pila == NULL) {
        new->disc.altura = 1;
    } else {
        new->disc.altura = (*pila)->disc.altura + 1;
    }

    new->disc.ancho = disco;
    new->next = *pila;
    *pila = new;
}

int is_Empty_DS(Node_DS *ds) {
    return ds == NULL;
}

int pop(Node_DS **ds, int *numNivel) {
    Node_DS *node_aux;
    int resp;

    if (is_Empty_DS(*ds))
        return 0;

    *numNivel = (*ds)->disc.altura;
    resp = (*ds)->disc.ancho;

    node_aux = (*ds)->next;
    free(*ds);
    *ds = node_aux;

    return resp;
}

void push(Node_DS **pilaCopia, DISCO disc) {
    Node_DS *nuevo = (Node_DS *) malloc(sizeof(Node_DS));
    nuevo->disc = disc;
    nuevo->next = NULL;

    if (*pilaCopia == NULL) {
        *pilaCopia = nuevo;
    } else {
        Node_DS *ultimo = *pilaCopia;
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }
        ultimo->next = nuevo;
    }
}

void copiar(Node_DS **pila, Node_DS **pilaCopia) {
    Node_DS *actual = *pila;

    while (actual != NULL) {
        push(pilaCopia, actual->disc);
        actual = actual->next;
    }
}

void borrarPila(Node_DS **pila) {
    Node_DS *actual, *siguiente;
    actual = *pila;

    while (actual != NULL) {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }

    *pila = NULL;
}

void mostrar(Node_DS **pilaA, Node_DS **pilaB, Node_DS **pilaC, int totalDiscos, int tamDiscoGrande) {
    Node_DS *pilaAc = NULL, *pilaBc = NULL, *pilaCc = NULL;
    int discoA, discoB, discoC, nivelA = 0, nivelB = 0, nivelC = 0;
    int espA, espB, espC;
    int numNivel;
    int i;

    copiar(pilaA, &pilaAc);
    copiar(pilaB, &pilaBc);
    copiar(pilaC, &pilaCc);

    discoA = pop(&pilaAc, &nivelA);
    discoB = pop(&pilaBc, &nivelB);
    discoC = pop(&pilaCc, &nivelC);

    for (numNivel = totalDiscos; numNivel > 0; numNivel--) {
        espA = (tamDiscoGrande - discoA) / 2;
        espB = (tamDiscoGrande - discoB) / 2;
        espC = (tamDiscoGrande - discoC) / 2;

        if (nivelA == numNivel) {
            for (i = 0; i < espA; i++)
                printf(" ");
            for (i = 0; i < discoA; i++)
                printf("*");
            for (i = 0; i < espA; i++)
                printf(" ");
            discoA = pop(&pilaAc, &nivelA);
        } else {
            for (i = 0; i < tamDiscoGrande; i++)
                printf(" ");
        }

        printf("  ");

        if (nivelB == numNivel) {
            for (i = 0; i < espB; i++)
                printf(" ");
            for (i = 0; i < discoB; i++)
                printf("*");
            for (i = 0; i < espB; i++)
                printf(" ");
            discoB = pop(&pilaBc, &nivelB);
        } else {
            for (i = 0; i < tamDiscoGrande; i++)
                printf(" ");
        }

        printf("  ");

        if (nivelC == numNivel) {
            for (i = 0; i < espC; i++)
                printf(" ");
            for (i = 0; i < discoC; i++)
                printf("*");
            for (i = 0; i < espC; i++)
                printf(" ");
            discoC = pop(&pilaCc, &nivelC);
        } else {
            for (i = 0; i < tamDiscoGrande; i++)
                printf(" ");
        }

        printf("\n");
    }
}

void mover(Node_DS **pilaA, Node_DS **pilaB, Node_DS **pilaC, int totDiscos, int tamDiscGrande, char listOrigen, char listDestino) {
    int aux = 0;

    if (listOrigen == 'A') {
        if (listDestino == 'B')
            pushD(pilaB, pop(pilaA, &aux));
        else if (listDestino == 'C')
            pushD(pilaC, pop(pilaA, &aux));
    } else if (listOrigen == 'B') {
        if (listDestino == 'A')
            pushD(pilaA, pop(pilaB, &aux));
        else if (listDestino == 'C')
            pushD(pilaC, pop(pilaB, &aux));
    } else if (listOrigen == 'C') {
        if (listDestino == 'A')
            pushD(pilaA, pop(pilaC, &aux));
        else if (listDestino == 'B')
            pushD(pilaB, pop(pilaC, &aux));
    }

    mostrar(pilaA, pilaB, pilaC, totDiscos, tamDiscGrande);
}

void hanoi(Node_DS **pilaA, Node_DS **pilaB, Node_DS **pilaC, int nDiscos, int totalDiscos, int tamDiscoGrande, char A, char B, char C) {
    if (nDiscos == 1) {
        system("cls");
        mover(pilaA, pilaB, pilaC, totalDiscos, tamDiscoGrande, A, C);
        Sleep(1000);
    } else {
        hanoi(pilaA, pilaB, pilaC, nDiscos-1, totalDiscos, tamDiscoGrande, A, C, B);
        system("cls");
        mover(pilaA, pilaB, pilaC, totalDiscos, tamDiscoGrande, A, C);
        Sleep(1000);
        hanoi(pilaA, pilaB, pilaC, nDiscos-1, totalDiscos, tamDiscoGrande, B, A, C);
    }
}
