#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

typedef struct {
    nodetype* front;
    nodetype* rear;
} Queue;

Queue* initialize() {
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if (Q != NULL) {
        Q->front = NULL;
        Q->rear = NULL;
    }
    return Q;
}

void initQueue(Queue* Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

bool isFull(Queue* q) {
    return false;
}

bool isEmpty(Queue* q) {
    return (q->rear == NULL);
}

void enqueue(Queue* Q, int num) {
    nodetype* temp = (nodetype*)malloc(sizeof(nodetype));
    if (temp != NULL) {
        temp->data = num;
        temp->next = Q->rear;
        Q->rear = temp;

        if (Q->front == NULL) {
            Q->front = temp;
        }
    } else {
        printf("Memory allocation failed.\n");
    }
}

int dequeue(Queue* Q) {
    if (Q->rear == NULL) {
        printf("Queue is empty.\n");
        return 0;
    }

    int value;

    if (Q->rear->next == NULL) {
        nodetype* temp = Q->rear;
        value = temp->data;

        Q->rear = NULL;
        Q->front = NULL;

        free(temp);
        return value;
    }

    nodetype* prev = Q->rear;
    nodetype* curr = Q->rear->next;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    value = curr->data;
    prev->next = NULL;
    Q->front = prev;

    free(curr);
    return value;
}

int peek(Queue* Q) {
    if (Q->front != NULL) {
        return Q->front->data;
    } else {
        printf("Queue is empty.\n");
        return 0;
    }
}

void display(Queue* Q) {
    if (Q->rear == NULL) {
        printf("Queue is empty.\n");
    } else {
        nodetype* trav;
        printf("Queue:");
        for (trav = Q->rear; trav != NULL; trav = trav->next) {
            printf(" %d", trav->data);
        }
        printf("\n");
    }
}

void insertSorted(Queue* Q, int data) {
    Queue temp1;
    initQueue(&temp1);

    while (!isEmpty(Q) && peek(Q) < data) {
        enqueue(&temp1, dequeue(Q));
    }

    enqueue(&temp1, data);

    while (!isEmpty(Q)) {
        enqueue(&temp1, dequeue(Q));
    }

    while (!isEmpty(&temp1)) {
        enqueue(Q, dequeue(&temp1));
    }
}

void makeEmpty(Queue* Q) {
    while (!isEmpty(Q)) {
        dequeue(Q);
    }
}

int main() {
    Queue A;
    initQueue(&A);

    enqueue(&A, 0);
    enqueue(&A, 14);
    enqueue(&A, 21);
    enqueue(&A, 28);

    insertSorted(&A, 17);

    display(&A);
    printf("Front: %d\n", peek(&A));

    printf("Dequeued: %d\n", dequeue(&A));
    display(&A);

    if (isEmpty(&A) == true) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    makeEmpty(&A);
    display(&A);

    return 0;
}
