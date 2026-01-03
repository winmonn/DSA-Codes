#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

void initQueue(Queue* Q) {
    Q->list.count = 0;
    Q->front = -1;
    Q->rear = -1;
}

bool isFull(Queue* Q) {
    return Q->list.count == MAX;
}

bool isEmpty(Queue* Q) {
    return Q->list.count == 0;
}

void enqueue(Queue* Q, int value) {
    if (isFull(Q)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(Q)) {
        Q->front = 0;
        Q->rear = 0;
    } else {
        Q->rear = (Q->rear + 1) % MAX;
    }

    Q->list.items[Q->rear] = value;
    Q->list.count++;
}

int dequeue(Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return 0;
    }

    int value = Q->list.items[Q->front];

    if (Q->list.count == 1) {
        Q->front = -1;
        Q->rear = -1;
        Q->list.count = 0;
    } else {
        Q->front = (Q->front + 1) % MAX;
        Q->list.count--;
    }

    return value;
}

int front(Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return 0;
    }
    return Q->list.items[Q->front];
}

void display(Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return;
    }

    int i;
    int idx = Q->front;

    printf("Queue: ");
    for (i = 0; i < Q->list.count; i++) {
        printf("%d ", Q->list.items[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue Q;
    initQueue(&Q);

    enqueue(&Q, 1);
    enqueue(&Q, 7);
    enqueue(&Q, 14);
    enqueue(&Q, 21);

    display(&Q);

    dequeue(&Q);
    display(&Q);

    enqueue(&Q, 28);
    display(&Q);

    printf("Front element: %d\n", front(&Q));

    return 0;
}
