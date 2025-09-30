#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(unsigned char* set){
    *set = 0;
}

void insertElem(unsigned char* set, int elem){
    int max = 8 * sizeof(*set);
    if(elem >= 0 && elem < max){
        unsigned char mask = 1 << elem;
        *set |= mask;
    } else {
        printf("Invalid index.\n");
    }
}

void deleteElem(unsigned char* set, int elem){
    int max = 8 * sizeof(*set);
    if(elem >= 0 && elem < max){
        unsigned char mask = 1 << elem;
        *set &= ~(mask);
    } else {
        printf("Invalid index.\n");
    }
}

bool find(unsigned char set, int elem){
    int max = 8 * sizeof(set);
    if(elem >= 0 && elem < max){
        unsigned char mask = 1 << elem;
        set &= mask;
    } else {
        printf("Invalid index.\n");
    }
    return (set == 1 << elem)? true: false;
}

unsigned char Union(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char Intersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char Difference(unsigned char A, unsigned char B){
    return A & ~(B);
}

void displaySet(unsigned char set){
    int max = 8 * sizeof(set);
    for(int i = 0; i < max; i++){
        if(set &  (1 << i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

void displayBits(unsigned char set){
    int max = 8 * sizeof(set);
    printf("Set:");
    int i = 0;
    unsigned char mask = 1 << max - 1;
    for(i = 0;  i < max; i++){
        ((set & mask) == mask) ? printf(" 1") : printf(" 0");
        mask >>= 1;
    }
    printf("\n");
}

int main() {
    unsigned char A;
    initialize(&A);
    insertElem(&A, 1);
    insertElem(&A, 6);
    bool found = find(A, 6);
    if(found == true){
        printf("Element found.\n");
    } else {
        printf("Element not found.\n");
    }
    // deleteElem(&A, 6);
    unsigned char B;
    initialize(&B);
    insertElem(&B, 7);
    insertElem(&B, 1);
    unsigned char U = Union(A, B);
    unsigned char I = Intersection(A, B);
    unsigned char D = Difference(A, B);
    displayBits(A);
    displaySet(A);
    displayBits(B);
    displaySet(B);
    displayBits(U);
    displaySet(U);
    displayBits(I);
    displaySet(I);
    displayBits(D);
    displaySet(D);
    
    return 0;
}
