#include <stdio.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

typedef enum {
    TRUE, FALSE
} boolean;

void initQueue(Queue* Q) {
    Q->front = 1;
    Q->rear = 0;
}

boolean isEmpty(Queue Q) {
    return (Q.front == (Q.rear + 1) % MAX) ? TRUE : FALSE;
}

boolean isFull(Queue Q) {
    return (Q.front == (Q.rear + 2) % MAX) ? TRUE : FALSE;
}

void enqueue(Queue* Q, int data) {
    if (isFull(*Q) == FALSE) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = data;
    } else {
        printf("Queue is full.\n");
    }
}

int dequeue(Queue* Q) {
    if (isEmpty(*Q) == FALSE) {
        int value = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAX;
        return value;
    } else {
        printf("Queue is empty.\n");
        return 0;
    }
}

int front(Queue* Q) {
    if (isEmpty(*Q) == FALSE) {
        return Q->data[Q->front];
    } else {
        printf("Queue is empty.\n");
        return 0;
    }
}

void display(Queue Q) {
    if (isEmpty(Q) == TRUE) {
        printf("Queue is empty.\n");
    } else {
        int x;
        printf("Queue: ");
        for (x = Q.front; x != (Q.rear + 1) % MAX; x = (x + 1) % MAX) {
            printf("%d ", Q.data[x]);
        }
        printf("\n");
    }
}

int main() {
    Queue A;
    initQueue(&A);

    enqueue(&A, 1);
    enqueue(&A, 7);
    enqueue(&A, 14);
    enqueue(&A, 21);
    display(A);

    dequeue(&A);
    display(A);

    enqueue(&A, 28);
    display(A);

    enqueue(&A, 35);
    dequeue(&A);
    display(A);

    printf("Front element: %d\n", front(&A));

    return 0;
}
