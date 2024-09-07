#include <stdio.h>
#include <stdlib.h>
#include "arbolbb.h"

//Rivera Plascencia Bryan
//Velazquez Trinidad Jazmin Montserrath

void main() {
    Tree arbol;
    crear_abb(&arbol);

    insert_abb(&arbol, 5780, "Calculo");
    insert_abb(&arbol, 4090, "Programacion");
    insert_abb(&arbol, 6890, "Economia");
    insert_abb(&arbol, 2098, "Algoritmos y estructuras de datos");
    insert_abb(&arbol, 5990, "Algebra lineal");
    insert_abb(&arbol, 4789, "Comunicacion oral y escrita");
    insert_abb(&arbol, 7865, "Bases de datos");

    printf("Resultados de la busqueda:\n");
    search_abb(arbol, 2098);
    search_abb(arbol, 6987);
    search_abb(arbol, 4789);

    printf("\nrecorrido preorden:\n");
    preorden(arbol);

    remove_abb(&arbol);
}
