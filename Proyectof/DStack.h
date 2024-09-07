#ifndef _DSTACK
#define _DSTACK


typedef struct DISCO {
    int ancho;
    int altura;
} DISCO;


typedef struct Node_DS {
    struct DISCO disc;
    struct Node_DS *next;
} Node_DS;


void create_DS(Node_DS **ds);

void pushD(Node_DS **pila, int disco);

int is_Empty_DS(Node_DS *ds);

int pop(Node_DS **ds, int *numNivel);

void push(Node_DS **pilaCopia, DISCO disc);

void copiar(Node_DS **pila, Node_DS **pilaCopia);

void borrarPila(Node_DS **pila);

void mostrar(Node_DS **pilaA, Node_DS **pilaB, Node_DS **pilaC, int totalDiscos, int tamDiscoGrande);

void mover(Node_DS **pilaA, Node_DS **pilaB, Node_DS **pilaC, int totDiscos, int tamDiscGrande, char listOrigen, char listDestino);

void hanoi(Node_DS **pilaA, Node_DS **pilaB, Node_DS **pilaC, int nDiscos, int totalDiscos, int tamDiscoGrande, char A, char B, char C);


#endif
