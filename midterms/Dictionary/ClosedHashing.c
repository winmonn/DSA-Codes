#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef enum {
    EMPTY,
    OCCUPIED,
    DELETED
} SlotStatus;

typedef struct {
    int data[MAX];
    SlotStatus status[MAX];
} Dictionary;

int Hash(int num) {
    return num % MAX;
}

void initDictionary(Dictionary* D) {
    int x;
    for (x = 0; x < MAX; x++) {
        D->status[x] = EMPTY;
        D->data[x] = 0;
    }
}

void insertLast(Dictionary* D, int num) {
    int h = Hash(num);
    int i;

    for (i = 0; i < MAX; i++) {
        int idx = (h + i) % MAX;

        if (D->status[idx] == OCCUPIED && D->data[idx] == num) {
            return;
        }

        if (D->status[idx] == EMPTY || D->status[idx] == DELETED) {
            D->data[idx] = num;
            D->status[idx] = OCCUPIED;
            return;
        }
    }

    printf("Dictionary is full.\n");
}

void insertFirst(Dictionary* D, int num) {
    insertLast(D, num);
}

void deleteFirst(Dictionary* D, int num) {
    int h = Hash(num);
    int i;

    for (i = 0; i < MAX; i++) {
        int idx = (h + i) % MAX;

        if (D->status[idx] == EMPTY) {
            return;
        }

        if (D->status[idx] == OCCUPIED && D->data[idx] == num) {
            D->status[idx] = DELETED;
            return;
        }
    }
}

void deleteLast(Dictionary* D, int num) {
    deleteFirst(D, num);
}

bool isMember(Dictionary* D, int num) {
    int h = Hash(num);
    int i;

    for (i = 0; i < MAX; i++) {
        int idx = (h + i) % MAX;

        if (D->status[idx] == EMPTY) {
            return false;
        }

        if (D->status[idx] == OCCUPIED && D->data[idx] == num) {
            return true;
        }
    }

    return false;
}

void display(Dictionary* D) {
    int x;
    printf("Index: ");
    for (x = 0; x < MAX; x++) {
        printf("%2d ", x);
    }
    printf("\n");

    printf("Data : ");
    for (x = 0; x < MAX; x++) {
        if (D->status[x] == OCCUPIED) {
            printf("%2d ", D->data[x]);
        } else {
            printf(" - ");
        }
    }
    printf("\n");
}

int main() {
    Dictionary A;
    initDictionary(&A);

    insertLast(&A, 7);
    insertLast(&A, 17);
    insertLast(&A, 27);

    insertFirst(&A, 24);
    insertFirst(&A, 14);
    insertFirst(&A, 4);

    deleteFirst(&A, 4);
    deleteLast(&A, 7);

    bool Member = isMember(&A, 17);
    if (Member == true) {
        printf("Member found.\n");
    } else {
        printf("Member not found.\n");
    }

    display(&A);

    return 0;
}
