#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int indice;
    int elemento;
} index;

typedef struct {
    int indice;
    int grupo;
} Resultado;

int busqueda_binaria(int *, int, int, int);
void mergeSort(int *, int, int);
void merge(int *, int, int, int);
void mostrar(int *, int);
Resultado indexed_search(int *, int, int);

int main(int argc, char *argv[]) {
    int *A;
    int n = atoi(argv[1]);

    A = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 5000 + 1;
    }

    mergeSort(A,0,n-1);

    mostrar(A,n);

    printf("\nIngresa el numero que deseas buscar: ");
    int x;
    scanf("%d",&x);
    printf("\n");

    Resultado p = indexed_search(A, n, x);

    if (p.indice != -1) {
        printf("El elemento %d se encuentra en el grupo %d, posicion %d.\n", x, p.grupo, p.indice);
    } else {
        printf("El elemento %d no se encuentra en el arreglo.\n", x);
    }

    free(A);
    return 0;
}

Resultado indexed_search(int *A, int n, int x) {
    int G = 8;  //numeros de grupos
    int GN = n / G; // elementos por grupi
    index tabla[G];
    int set = 0;
    int ini, fin;
    int j = 0;
    for (int i = 0; i < n; i += GN) {
        tabla[j].indice = i;
        tabla[j].elemento = A[i];
        j++;
    }

    Resultado r;
    r.indice = -1;
    r.grupo = -1;

    if (x < tabla[0].elemento) {
        return r;
    } else {
        int i;
        for (i = 1; i < G; i++) {
            if (x < tabla[i].elemento) {
                set = 1;
                ini = tabla[i - 1].indice;
                fin = tabla[i].indice - 1;
                r.grupo = i;
                break;
            }
        }

        if (set == 0) {
            ini = tabla[G - 1].indice;
            fin = n - 1;
            r.grupo = G;
        }

        r.indice = busqueda_binaria(A, x, ini, fin);
        if (r.indice != -1) {
            r.indice = r.indice + 1;
        }
        return r;
    }
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