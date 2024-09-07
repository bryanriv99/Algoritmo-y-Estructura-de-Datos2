#include <stdio.h>
#define size 10
#define true 1
#define false 0
typedef int element;

typedef struct Stack {
    element array[size];
    int top;
} sstack;

//funciones

void createss(sstack *s) {
    s->top = -1;
}

int isemptys(sstack *s) {
    if(s->top == -1) {
        return true;
    } else {
        return false;
    }
}

int isfulls(sstack *s) {
    if(s->top == size - 1) {
        return true;
    } else {
        return false;
    }
}

void pushs(sstack *s, element e) {
    if(isfulls(s)) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->array[s->top] = e;
    }
}

int pops(sstack *s) {
    if(isemptys(s)) {
        printf("Stack is empty\n");
    } else {
        s->top--;
        return s->array[s->top + 1];
    }
}

void prints(sstack *s) {
    int i;
    for(i = 0; i <= s->top; i++) {
        printf("%d ", s->array[i]);
    }
    printf("\n");
}