#include <stdio.h>
#include <stdlib.h>

#define LENGTH 3

typedef int elem[LENGTH];

typedef struct {
    int* elemPtr;
    int count;
    int max;
}List;

List initialize(List L){
    L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L.count = 0;
    L.max = LENGTH;
    
    return L;
}

List resize(List L){
    L.max *= 2; 
    L.elemPtr = realloc(L.elemPtr, L.max * sizeof(int));
    
    return L;
}

List insertPos(List L, int data, int pos){
    
    if(L.count == LENGTH){
        L = resize(L);
    }
    
    if(pos >= 0 && pos < LENGTH){
        int i = L.count - 1 , j= L.count;
        for(; j > pos; i--, j--){
            L.elemPtr[j] = L.elemPtr[i]; 
        }
        L.elemPtr[pos] = data;
        (L.count)++;
    } else {
        printf("Position invalid.\n");
    }
    return L;
}

List deletePos(List L, int pos){
    if(L.count > 0 ){
        if(pos >= 0 && pos < L.max){
            int i = pos, j = pos + 1;
            for(;j < L.count; i++, j++){
                L.elemPtr[i] = L.elemPtr[j];
            }
            (L.count)--;
        } else {
            printf("Position invalid.\n");
        }
    } else {
        printf("List is empty.\n");
    }
    
    return L;
}

List insertSorted(List L , int data){
    if(L.count == L.max){
        resize(L);
    }
    int i, j;
    for(i = 0; i < L.count && L.elemPtr[i] < data; i++){}
    int pos = i;
    for(i = L.count - 1, j = L.count; j > pos; i--, j--){
        L.elemPtr[j] = L.elemPtr[i]; 
    }
    L.elemPtr[pos] = data;
    (L.count)++;

    return L;
}

int locate(List L, int data){
    int i;
    for(i = 0; i < L.count && L.elemPtr[i] != data; i++){}
    return(i == L.count)? -1 : i; 
}

int retrieve(List L, int position){
    int i;
    if(position >= 0 && position < L.count){
        for(i = 0; i < L.count && i != position; i++){}   
    } else {
        printf("Position invalid.\n");
    }
    return(position >= 0 && position < L.count)? L.elemPtr[i] : -1;
}

void display(List L){
    int i;
    printf("List: ");
    for(i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}

void makeNull(List L){
    free(L.elemPtr);
}

int main() {
    List L = initialize(L);
    L = insertPos(L, 7, 0);
    L = insertPos(L, 14, 1);
    L = insertPos(L, 21, 2);
    L = insertPos(L, 17, 2);
    L = deletePos(L, 2);
    L = insertSorted(L, 19);
    display(L);
    int index = locate(L, 19);
    printf("Index of the data: %d\n", index);
    int position = retrieve(L, 2);
    printf("Data in the position: %d\n", position);
    makeNull(L);

    return 0;
}