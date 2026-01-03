#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct node{
    int data;
    struct node* next;
}*Node;

typedef Node Dictionary[MAX];

void initDictionary(Dictionary D){
    int x;
    for(x = 0; x < MAX; x++){
        D[x] = NULL;
    }
}

int Hash(int num){
    return num % 10;
}

void insertFirst(Dictionary D, int num){
    int value = Hash(num);
    Node New = (Node)malloc(sizeof(struct node));
    if(New != NULL){
        New->data = num;
        New->next = D[value];
        D[value] = New;
    }
}

void insertLast(Dictionary D, int num){
    int value = Hash(num);
    struct node* New = (struct node*)malloc(sizeof(struct node));
    if(New != NULL){
        New->data = num;
        New->next = NULL;
        Node* trav;
        for(trav = &D[value]; *trav != NULL; trav = &(*trav)->next){}
        *trav = New;
    }
}

void deleteFirst(Dictionary D, int index){
    Node temp = D[index];
    D[index] = temp->next;
    free(temp);
}

void deleteLast(Dictionary D, int index){
    Node* trav;
    for(trav = &D[index]; (*trav)->next != NULL; trav = &(*trav)->next){}
    Node temp = *trav;
    *trav = temp->next;
    free(temp);
}

bool isMember(Dictionary D, int data){
    int value = Hash(data);
    Node trav;
    for(trav = D[value]; trav != NULL && trav->data != data; trav = trav->next){}
    return(trav != NULL)? true: false;
}

int main() {
    
    Dictionary A;
    initDictionary(A);
    insertLast(A, 7);
    insertLast(A, 17);
    insertLast(A, 27);
    insertFirst(A, 24);
    insertFirst(A, 14);
    insertFirst(A, 4);
    deleteFirst(A, 4);
    deleteLast(A, 7);
    bool Member = isMember(A, 17);
    if(Member == true){
        printf("Member found.\n");
    } else {
        printf("Member not found.\n");
    }

    return 0;
}