#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} nodeType, *Stack;

Stack* initialize() {
    Stack* S = (Stack*)malloc(sizeof(Stack));
    if (S != NULL) {
        *S = NULL;
    }
    return S;
}

void initStack(Stack* A) {
    *A = NULL;
}

bool isFull(Stack* s) {
    return false;
}

bool isEmpty(Stack* s) {
    return (*s == NULL);
}

void push(Stack* A, int num) {
    Stack temp = (Stack)malloc(sizeof(nodeType));
    if (temp != NULL) {
        temp->data = num;
        temp->next = *A;
        *A = temp;
    } else {
        printf("Malloc failed.\n");
    }
}

int pop(Stack* A) {
    if (*A != NULL) {
        Stack temp = *A;
        int value = temp->data;
        *A = temp->next;
        free(temp);
        return value;
    } else {
        printf("Stack is empty.\n");
        return 0;
    }
}

int peek(Stack* A) {
    if (*A != NULL) {
        return (*A)->data;
    } else {
        printf("Stack is empty.\n");
        return 0;
    }
}

void display(Stack* A) {
    if (*A == NULL) {
        printf("Stack is empty.\n");
    } else {
        Stack trav;
        printf("Stack:");
        for (trav = *A; trav != NULL; trav = trav->next) {
            printf(" %d", trav->data);
        }
        printf("\n");
    }
}

void makeEmpty(Stack* A) {
    while (*A != NULL) {
        pop(A);
    }
}

int main() {
    Stack* X = initialize();
    if (X == NULL) {
        printf("Malloc failed.\n");
        return 0;
    }

    push(X, 7);
    push(X, 14);
    push(X, 21);

    printf("Top: %d\n", peek(X));
    display(X);

    printf("Popped: %d\n", pop(X));
    printf("Popped: %d\n", pop(X));
    printf("Popped: %d\n", pop(X));

    if (isEmpty(X) == true) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    makeEmpty(X);
    free(X);

    return 0;
}
