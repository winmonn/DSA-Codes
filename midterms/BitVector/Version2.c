// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int field : 8;
}Set;

void initialize(Set* set){
    set->field = 0;
}

void insertElem(Set* set, int elem){
    if(elem >= 0 && elem < 8){
        set->field |= 1 << elem;
    }
}

void deleteElem(Set* set, int elem){
    if(elem >= 0 && elem < 8){
        set->field &= ~(1 << elem);
    }
}

bool find(Set set, int elem){
    if(elem >= 0 && elem < 8){
        return(set.field & (1 << elem));
    }
}

Set Union(Set A, Set B){
    Set U;
    U.field = A.field | B.field;
    return U;
}

Set Intersection(Set A, Set B){
    Set I;
    I.field = A.field & B.field;
    return I;
}

Set Difference(Set A, Set B){
    Set D;
    D.field = A.field & ~(B.field);
    return D;
}

void display(Set set){
    printf("Set: ");
    for(int i = 0; i < 8; i ++){
        if(set.field & (1 << i)){
            printf("%d ",i);
        }
    }
    printf("\n");
}

int main() {
    
    Set A;
    initialize(&A);
    insertElem(&A, 0);
    printf("%d\n", A.field);
    insertElem(&A, 4);
    printf("%d\n", A.field);
    insertElem(&A, 5);
    printf("%d\n", A.field);
    // deleteElem(&A, 4);
    // printf("%d\n", A.field);
    bool found = find(A, 5);
    (found == true)? printf("Element found.\n") : printf("Element not found.\n");
    Set B;
    initialize(&B);
    insertElem(&B, 2);
    printf("%d\n", B.field);
    insertElem(&B, 5);
    printf("%d\n", B.field);
    Set U = Union(A, B);
    printf("%d\n", U.field);
    Set I = Intersection(A, B);
    printf("%d\n", I.field);
    Set D = Difference(A, B);
    printf("%d\n", D.field);
    display(A);
    display(B);
    display(U);
    display(I);
    display(D);
    
    
    return 0;
}
