#include <stdio.h>
#include <stdlib.h>

//Rivera Plascencia Bryan

int busqueda_binaria(int *, int, int, int);
void mergeSort(int *, int, int);
void merge(int *, int, int, int);
void mostrar(int *, int);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamaño>\n", argv[0]);
        return 1;
    }

    int tam = atoi(argv[1]);
    int *A;
    A = (int *)malloc(tam * sizeof(int));
    
    for (int i = 0; i < tam; i++) {
        A[i] = rand() % 5001 + 10000; // Genera números entre 10000 y 15000
    }

    mergeSort(A, 0, tam - 1);
    mostrar(A, tam);
    
    int n;
    printf("\nIngrese el numero a buscar: ");
    scanf("%d", &n);
    
    int s;
    s = busqueda_binaria(A, n, 0, tam - 1);
    
    if (s == -1) {
        printf("\nEl numero %d no se encuentra en el arreglo\n",n);
    } else {
        printf("\nEl numero %d se encuentra en la posicion %d\n", n,s+1);
    }

    free(A); // Libera la memoria asignada
    return 0;
}

int busqueda_binaria(int *A, int s, int ini, int fin) {
    while (ini <= fin) {
        int mit = (ini + fin) / 2;
        
        if (s == A[mit]) {
            return mit;
        } else if (s < A[mit]) {
            fin = mit - 1;
        } else {
            ini = mit + 1;
        }
    }
    return -1;
}

void mostrar(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
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
