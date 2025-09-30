#include <stdio.h>
#include <stdbool.h>

#define MAX 8

typedef bool Set[MAX];

void initialize(Set set){
    for(int i = 0; i < MAX; i++){
        set[i] = false;
    }
}

void insertElem(Set set, int elem){
    if(elem >= 0 && elem < MAX){
        int i;
        for(i = 0; i < MAX && i != elem; i++){}
        set[i] = true;
    }
}

void deleteElem(Set set, int elem){
    if(elem >= 0 && elem < MAX){
        int i;
        for(i = 0; i < MAX && i != elem; i++){}
        set[i] = false;
    }
}

bool find(Set set, int elem){
    if(elem >= 0 && elem < MAX){
        int i;
        for(i = 0; i < MAX && i != elem; i++){}
        return(set[i] == true);
    }
}

void Union(Set A, Set B, Set C){
    int i;
    for(i = 0 ; i < MAX; i++){
        if(A[i] == 1 || B[i] == 1){
            C[i] = true;
        } else {
            C[i] = false;
        }
    }
}

void Intersection(Set A, Set B, Set C){
    int i;
    for(i = 0 ; i < MAX; i++){
        if(A[i] == 1 && B[i] == 1){
            C[i] = true;
        } else {
            C[i] = false;
        }
    }
}

void Difference(Set A, Set B, Set C){
    int i;
    for(i = 0 ; i < MAX; i++){
        if(A[i] == 1 && B[i] == 0){
            C[i] = true;
        } else {
            C[i] = false;
        }
    }
}

void displayBits(Set set){
    int i;
    printf("Set: ");
    for(i = 0; i < MAX; i++){
        printf("%d ", set[i]);
    }
    printf("\n");
}

void displaySet(Set set){
    int i;
    printf("Set: ");
    for(i = 0; i < MAX; i++){
        if(set[i] == 1){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    Set A;
    initialize(A);
    insertElem(A, 0);
    insertElem(A, 2);
    insertElem(A, 7);
    // deleteElem(A, 0);
    // deleteElem(A, 7);
    bool found = find(A, 7);
    (found == true)? printf("Element found.\n") : printf("Element not found.\n");
    Set B;
    initialize(B);
    insertElem(B, 2);
    insertElem(B, 4);
    insertElem(B, 5);
    displaySet(A);
    displaySet(B);
    Set C;
    Union(A, B, C);
    displaySet(C);
    Intersection(A, B, C);
    displaySet(C);
    Difference(A, B, C);
    displaySet(C);

    return 0;
}
