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
    return (q->front == NULL);
}

void enqueue(Queue* Q, int num) {
    nodetype* temp = (nodetype*)malloc(sizeof(nodetype));
    if (temp != NULL) {
        temp->data = num;
        temp->next = NULL;

        if (Q->front == NULL) {
            Q->front = temp;
        } else {
            Q->rear->next = temp;
        }
        Q->rear = temp;
    } else {
        printf("Memory allocation failed.\n");
    }
}

int dequeue(Queue* Q) {
    if (Q->front != NULL) {
        nodetype* temp = Q->front;
        int value = temp->data;

        Q->front = temp->next;
        if (Q->front == NULL) {
            Q->rear = NULL;
        }

        free(temp);
        return value;
    } else {
        printf("Queue is empty.\n");
        return 0;
    }
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
    if (Q->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        nodetype* trav;
        printf("Queue:");
        for (trav = Q->front; trav != NULL; trav = trav->next) {
            printf(" %d", trav->data);
        }
        printf("\n");
    }
}

void insertSorted(Queue* Q, int data) {
    Queue temp1;
    initQueue(&temp1);

    while (Q->front != NULL && Q->front->data < data) {
        enqueue(&temp1, dequeue(Q));
    }

    enqueue(&temp1, data);

    while (Q->front != NULL) {
        enqueue(&temp1, dequeue(Q));
    }

    while (temp1.front != NULL) {
        enqueue(Q, dequeue(&temp1));
    }
}

void makeEmpty(Queue* Q) {
    while (Q->front != NULL) {
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
