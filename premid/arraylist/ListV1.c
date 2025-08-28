#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main(){
    List L = initialize(L);
	L = insertPos(L, 7, 0);
	L = insertPos(L, 14, 1);
	L = insertPos(L, 21, 2);
	L = insertPos(L, 28, 3);
	L = insertPos(L, 35, 4);
	L = insertPos(L, 17, 2);
	L = deletePos(L, 2);
	L = insertSorted(L, 17);
	
	int pos = locate(L, 14);
	printf("Position: %d\n", pos);

	display(L);

}

List initialize(List L){
    L.count = 0;

    return L;
}

List insertPos(List L, int data, int position){
	if(position <= MAX - 1){
		if(L.count < MAX){
			int i, j;
			for(i = L.count - 1, j = L.count; j > position ;i--, j--){
				L.elem[j] = L.elem[i];
			}
			(L.count)++;
			L.elem[position] = data;
		} else {
			printf("List is full.\n");
		}
	} else {
		printf("Invalid position.\n");
	}
	
	return L;
}

List deletePos(List L, int position){
	if(position <= MAX - 1){
		if(L.count > 0){
			int i, j;
			for(i = position, j = position + 1; j < L.count; i++, j++){
				L.elem[i] = L.elem[j];
			}
			(L.count)--;
		} else {
			printf("List is empty.\n");
		}	
	} else {
		printf("Position is invalid.\n");
	}
	
	return L;
}

int locate(List L, int data){
	int i;
	for(i = 0; i < L.count && L.elem[i] != data; i++){}
	return (i < L.count) ? i : -1;
}

List insertSorted(List L, int data){
    int pos = 0;
    int i,j;
    for(i = 0; i < L.count && L.elem[i] < data; i++){}
    pos = i;
    for(i = L.count - 1, j = L.count; j > pos; i--, j--){
        L.elem[j] = L.elem[i];
    }
    (L.count)++;
    L.elem[pos] = data;
    
    return L;
}

void display(List L){
	int i;
	printf("List: ");
	for(i = 0; i < L.count; i++){
		if(i < L.count - 1){
			printf("%d, ", L.elem[i]);
		} else {
			printf("%d", L.elem[i]);
		}
	}
	printf("\n");
}