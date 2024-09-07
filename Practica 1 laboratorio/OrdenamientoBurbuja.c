#include <stdio.h>
#include <stdlib.h>

void burbuja(int A[], int n);
void intercambiar(int *, int *);

void main(){
    int n, i;
    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d",&n);

    int *A = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        A[i] = rand()%200;
    }
    printf("\nArreglo sin ordenar:\n");


    for(i = 0; i < n; i++){
        printf("%d  ",A[i]);
    }

    printf("\n");
    burbuja(A,n);

    printf("Arreglo ordenado:\n");
    for(i = 0; i < n; i++){
        printf("%d  ",A[i]);
    }

    free(A);
}

void intercambiar(int *A, int *B){
    int aux;
    aux = *A;
    *A = *B;
    *B = aux;
}

void burbuja(int A[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n - 1; j++){
            if(A[j] > A[j+1]){
                intercambiar(&A[j], &A[i+1]);
            }
        }
    }
}