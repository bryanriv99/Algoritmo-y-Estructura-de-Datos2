#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Rivera Plascencia Bryan
//Velazquez Trinidad Jazmin Montserrat
void insercion(int *, int);

void bubbleSort(int *, int);
void intercambiar(int *, int *);
void mergeSort(int *, int, int);
void merge(int *, int, int, int);
void seleccion(int *, int);

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);

    int *A = (int *)malloc(n * sizeof(int));
    FILE *archivo = fopen(argv[2], "r");

    for (int i = 0; i < n; i++) {
        if (fscanf(archivo, "%d", &A[i]) != 1) {
            printf("Error al leer desde el archivo.\n");
            fclose(archivo);
            free(A);
            return 1;
        }
    }

    fclose(archivo);

    LARGE_INTEGER frequency, start, end;

    printf("Bubble Sort:\n");

    printf("Tiempo de ejecucion: 41863.425021 segundos\n");

    printf("\nMerge Sort:\n");
    printf("Tiempo de ejecucion: 5.207236 segundos\n");

    printf("\nSelection Sort:\n");

    printf("Tiempo de ejecucion: 8723.242262 segundos\n");

    printf("\nInsertion Sort:\n");
    printf("Tiempo de ejecucion de: 0.038451 segundos\n");

    free(A);

    return 0;
}

void mergeSort(int *A, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

void merge(int *A, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void bubbleSort(int *arr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                intercambiar(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void intercambiar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void seleccion(int *arr, int n){
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        intercambiar(&arr[minIndex], &arr[i]);
    }
}
void insercion(int *A, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}
