#ifndef _DSTACK
#define _DSTACK
typedef int element;

typedef struct Node_DS{
    element e;
    struct Node_DS *next;
}Node_DS;

void create_DS(Node_DS **ds);
void push_DS(Node_DS **ds,element e);
int is_Empty_DS(Node_DS *ds);
element pop_DS(Node_DS **ds);
void printDS(Node_DS *ds);
void llenarPila(Node_DS **P);



#endif
