#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

typedef struct{
    char elems[MAX];
    int top;
}Stack;

void initStack(Stack* S){
    S->top = -1;
}

void push(Stack* S, char data){
    if(S->top < MAX - 1){
        S->elems[++(S->top)] = data;
    } else {
        printf("Stack is full.\n");
    }
}

void pop(Stack* S){
    if(S->top >= 0){
        (S->top)--;
    } else {
        printf("Stack is empty.");
    }
}

char peek(Stack S){
    return S.elems[S.top];
}

bool isFull(Stack S){
    return (S.top == MAX - 1);
}

bool isEmpty(Stack S){
    return (S.top < 0);
}

int main(){
    Stack A;
    initStack(&A);
    push(&A, 'W');
    push(&A, 'I');
    push(&A, 'N');
    char top = peek(A);
    printf("Top Character: %c", top);
    printf("\n");
    pop(&A);
    pop(&A);
    top = peek(A);
    printf("Top Character: %c", top);
    printf("\n");
    push(&A, 'O');
    push(&A, 'W');
    
    bool full = isFull(A);
    if (full == true){
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }
    
    bool empty = isEmpty(A);
    if (empty == true){
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}