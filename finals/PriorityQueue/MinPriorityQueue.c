#include <stdio.h>
#include <stdbool.h>

#define MAX 20

typedef struct {
    int elems[MAX];
    int count;
} PriorityQueue;

void initPQ(PriorityQueue* PQ) {
    PQ->count = 0;
}

bool isFull(PriorityQueue* PQ) {
    return PQ->count == MAX;
}

bool isEmpty(PriorityQueue* PQ) {
    return PQ->count == 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* PQ, int index) {
    int child = index;
    int parent = (child - 1) / 2;

    while (child > 0 && PQ->elems[child] < PQ->elems[parent]) {
        swap(&PQ->elems[child], &PQ->elems[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

void heapifyDown(PriorityQueue* PQ, int index) {
    int parent = index;

    while (1) {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;
        int smallest = parent;

        if (left < PQ->count && PQ->elems[left] < PQ->elems[smallest]) {
            smallest = left;
        }

        if (right < PQ->count && PQ->elems[right] < PQ->elems[smallest]) {
            smallest = right;
        }

        if (smallest != parent) {
            swap(&PQ->elems[parent], &PQ->elems[smallest]);
            parent = smallest;
        } else {
            break;
        }
    }
}

void enqueue(PriorityQueue* PQ, int value) {
    if (isFull(PQ)) {
        printf("Priority Queue is full.\n");
        return;
    }

    PQ->elems[PQ->count] = value;
    heapifyUp(PQ, PQ->count);
    PQ->count++;
}

int dequeue(PriorityQueue* PQ) {
    if (isEmpty(PQ)) {
        printf("Priority Queue is empty.\n");
        return 0;
    }

    int value = PQ->elems[0];
    PQ->count--;
    PQ->elems[0] = PQ->elems[PQ->count];
    heapifyDown(PQ, 0);

    return value;
}

int peek(PriorityQueue* PQ) {
    if (isEmpty(PQ)) {
        printf("Priority Queue is empty.\n");
        return 0;
    }
    return PQ->elems[0];
}

void display(PriorityQueue* PQ) {
    if (isEmpty(PQ)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    int x;
    printf("Priority Queue: ");
    for (x = 0; x < PQ->count; x++) {
        printf("%d ", PQ->elems[x]);
    }
    printf("\n");
}

int main() {
    PriorityQueue PQ;
    initPQ(&PQ);

    enqueue(&PQ, 14);
    enqueue(&PQ, 7);
    enqueue(&PQ, 21);
    enqueue(&PQ, 28);
    enqueue(&PQ, 17);

    display(&PQ);

    printf("Peek: %d\n", peek(&PQ));

    printf("Dequeue: %d\n", dequeue(&PQ));
    printf("Dequeue: %d\n", dequeue(&PQ));

    display(&PQ);

    return 0;
}
