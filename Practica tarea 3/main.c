#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

void llenarCola(Dqueue *, int);
void agregarCliente(Dqueue *);
void atender(Dqueue *, int);
void imprimirDatos(Cliente, int, int);


void main(){
    int cantClientes = rand() % 3;
    Dqueue cola;

    printf("Cantidad de clientes: %d\n", cantClientes);
    createDQ(&cola);
    llenarCola(&cola, cantClientes);
    atender(&cola, cantClientes);
}

void atender(Dqueue *dq, int cantClientes){
    int minutos = 0;
    int hora = 8;
    int numClientes = cantClientes;
    while(hora <16 && !isEmpty(dq)){
        Cliente c;
        c = dequeue(dq);
        int minutosaAgregar = rand() % 81 + 20;
        if(minutos + minutosaAgregar >= 60){
            minutos = minutos + minutosaAgregar - 60;
            hora++;
        } else {
            minutos += minutosaAgregar;
        }
        imprimirDatos(c, hora, minutos);
        numClientes--;
    }
    if(numClientes > 0){
        printf("Quedaron %d clientes sin atender", numClientes);
        while(dq->head != NULL){
            Cliente c = dequeue(dq);
            printf("\nCliente %d\n", c.identificador);
        }
    }
}

void imprimirDatos(Cliente c, int hora, int minutos){
    printf("\nCliente %d\n", c.identificador);
    printf("Asunto: %d\n", c.asunto);
    printf("Hora de atencion: %d:%d\n", hora, minutos);
}

void llenarCola(Dqueue *dq, int cantClientes){
    int i = 0;
    while(i < cantClientes){
        agregarCliente(dq);
        i++;
    }
}

void agregarCliente(Dqueue *dq){
    Cliente nuevoCliente;
    printf("\n(1.- Compra de alimentos)\n(2.- Devolucion)\n(3.- Cambio)\n(4.-Dudas)\n(5.-Otro)\nSelecione el asunto: ");
    scanf("%d",&nuevoCliente.asunto);
    printf("\nIngrese su identificador(id numerico): ");
    scanf("%d",&nuevoCliente.identificador);
    enqueue(dq, nuevoCliente);
}