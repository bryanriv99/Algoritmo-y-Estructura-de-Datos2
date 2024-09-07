#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "DStack.h"
#include <math.h>



int main() {
    Node_DS *pilaA, *pilaB, *pilaC;
    create_DS(&pilaA);
    create_DS(&pilaB);
    create_DS(&pilaC);
    int nDiscos, tamDiscGrande,disco;
    int i;
    int movimientostotales;
    do{
    printf("Ingresa el numero de discos (Entre 1 y 8):");
    scanf("%i", &nDiscos);
    }while(nDiscos < 1 || nDiscos > 8);
    movimientostotales=((pow(2,nDiscos))-1);
    disco = 1 + 2*(nDiscos - 1);  
    tamDiscGrande = disco;

    for (i = 0; i < nDiscos; i++) {
        pushD(&pilaA, disco);  
        disco -= 2;  
          }

    system("cls");
    mostrar(&pilaA, &pilaB, &pilaC, nDiscos, tamDiscGrande); 
    Sleep(1000);


    hanoi(&pilaA, &pilaB, &pilaC, nDiscos, nDiscos, tamDiscGrande, 'A', 'B', 'C');
    printf("\n\nNumero total de movimientos: %d",movimientostotales);

    borrarPila(&pilaA);
    borrarPila(&pilaB);
    borrarPila(&pilaC);
    return 0;
}