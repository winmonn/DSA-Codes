#include <stdio.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap* V) {
    int i;
    V->H[0].next = -1;
    for (i = 1; i < MAX; i++) {
        V->H[i].next = i - 1;
    }
    V->avail = MAX - 1;
}

int allocSpace(VHeap* V) {
    int space = V->avail;
    if (space != -1) {
        V->avail = V->H[space].next;
    }
    return space;
}

void insertFirst(int* L, VHeap* V, int elem) {
    int space = allocSpace(V);
    if (space != -1) {
        V->H[space].elem = elem;
        V->H[space].next = *L;
        *L = space;
    } else {
        printf("Virtual Heap is Full.\n");
    }
}

void insertLast(int* L, VHeap* V, int elem) {
    int space = allocSpace(V);
    if (space != -1) {
        V->H[space].elem = elem;
        V->H[space].next = -1;

        int* trav;
        for (trav = L; *trav != -1; trav = &(V->H[*trav].next)) { }
        *trav = space;
    } else {
        printf("Virtual Heap is Full.\n");
    }
}

void insertSorted(int* L, VHeap* V, int elem) {
    int space = allocSpace(V);
    if (space != -1) {
        V->H[space].elem = elem;

        List* trav;
        for (trav = L; *trav != -1 && V->H[*trav].elem < elem; trav = &V->H[*trav].next) { }
        V->H[space].next = *trav;
        *trav = space;
    } else {
        printf("Virtual Heap is Full.\n");
    }
}

void deallocSpace(VHeap* V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void deleteElem(int* L, VHeap* V, int elem) {
    int* trav;
    int temp;

    for (trav = L; *trav != -1 && V->H[*trav].elem != elem; trav = &V->H[*trav].next) { }

    if (*trav != -1) {
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    } else {
        printf("Element not found.\n");
    }
}

void deleteAllOccur(int* L, VHeap* V, int elem) {
    int* trav;
    int temp;

    for (trav = L; *trav != -1; ) {
        if (V->H[*trav].elem == elem) {
            temp = *trav;
            *trav = V->H[*trav].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}

void display(int L, VHeap V) {
    List trav;
    printf("List:");
    for (trav = L; trav != -1; trav = V.H[trav].next) {
        printf(" %d", V.H[trav].elem);
    }
    printf("\n");
}

int main() {
    VHeap VH;
    List L = -1;

    initialize(&VH);

    insertFirst(&L, &VH, 14);
    insertFirst(&L, &VH, 7);
    insertLast(&L, &VH, 28);
    insertSorted(&L, &VH, 14);

    display(L, VH);

    deleteAllOccur(&L, &VH, 14);
    display(L, VH);

    return 0;
}
