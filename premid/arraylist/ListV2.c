#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef struct {
    int elem[MAX];
    int count;
} *EPtr, Etype;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
void insertSorted(EPtr L, int data);
void display(EPtr L);

int main(){
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);
	insertPos(L, 7, 0);
	insertPos(L, 14, 1);
	insertPos(L, 21, 2);
	insertPos(L, 28, 3);
	insertPos(L, 35, 4);
	insertPos(L, 17, 2);
	deletePos(L, 2);
	insertSorted(L, 17);
	
	int pos = locate(L, 14);
	printf("Position: %d\n", pos);

	display(L);

}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
	if(position <= MAX - 1){
		if(L->count < MAX){
			int i, j;
			for(i = L->count - 1, j = L->count; j > position ;i--, j--){
				L->elem[j] = L->elem[i];
			}
			(L->count)++;
			L->elem[position] = data;
		} else {
			printf("List is full.\n");
		}
	} else {
		printf("Invalid position.\n");
	}
	
}

void deletePos(EPtr L, int position){
	if(position <= MAX - 1){
		if(L->count > 0){
			int i, j;
			for(i = position, j = position + 1; j < L->count; i++, j++){
				L->elem[i] = L->elem[j];
			}
			(L->count)--;
		} else {
			printf("List is empty.\n");
		}	
	} else {
		printf("Position is invalid.\n");
	}
	
}

int locate(EPtr L, int data){
	int position = 0;
	int i;
	for(i = 0; i < L->count && L->elem[i] != data; i++){}
	return (i < L->count) ? i : -1;
}

void insertSorted(EPtr L, int data){
    int pos = 0;
    int i,j;
    for(i = 0; i < L->count && L->elem[i] < data; i++){}
    pos = i;
    for(i = L->count - 1, j = L->count; j > pos; i--, j--){
        L->elem[j] = L->elem[i];
    }
    (L->count)++;
    L->elem[pos] = data;
    
}

void display(EPtr L){
	int i;
	printf("List: ");
	for(i = 0; i < L->count; i++){
		if(i < L->count - 1){
			printf("%d, ", L->elem[i]);
		} else {
			printf("%d", L->elem[i]);
		}
	}
	printf("\n");
}