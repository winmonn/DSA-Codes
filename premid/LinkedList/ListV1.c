#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct {
    Node* head;
    int count;
}List;

List* initList(){
    List* L = (List*)malloc(sizeof(List));
    if(L != NULL){
        L->head = NULL;
        L->count = 0;
    }
    return L;
}

void empty(List* L){
    
    Node* trav;
    Node* temp = NULL;
    for(trav = L->head; trav != NULL;){
        L->head = trav->next;
        temp = trav;
        trav = L->head;
        free(temp);
    }
    L->head = NULL;
    L->count = 0;
}

void insertFirst(List* L, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = L->head;
        L->head = newNode;
        (L->count)++;
    }
}

void insertLast(List* L, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = NULL;
        Node* trav;
        for(trav = L->head; trav->next != NULL; trav = trav->next){}
        trav->next = newNode;
        (L->count)++;
    }
}

void insertPos(List* L, int data, int index){
    if(index > 0 && index < L->count){
        Node* newNode = (Node*)malloc(sizeof(Node));
        if(newNode != NULL){
            newNode->data = data;
            newNode->next = NULL;
            int pos = 0;
            Node* trav;
            for(trav = L->head; trav->next != NULL && pos != index - 1; trav = trav->next, pos++){}
            newNode->next = trav->next;
            trav->next = newNode;
            (L->count)++;
        }
    } else if(index == 0){
        insertFirst(L, data);
    } else if(index == L->count){
        insertLast(L, data);
    } else {
        printf("Index is invalid.\n");
    }
}

void deleteFirst(List* L){
    if(L->head != NULL){
        Node* temp = L->head;
        L->head = temp->next;   
        free(temp);
    } else {
        printf("List is empty.\n");
    }
    (L->count)--;
}

void deleteLast(List* L){
    Node* trav = L->head;
    Node* temp = trav->next;
    for(;temp->next != NULL; trav = trav->next, temp = temp->next){}
    trav->next = NULL;
    free(temp);
    (L->count)--;
}

void deletePos(List* L, int index){
    if(index == 0){
        deleteFirst(L);
    } else if (index > 0 && index < L->count){
        Node* trav;
        int pos = 0;
        for(trav = L->head; trav->next != NULL && pos != index - 1; trav = trav->next, pos++){}
        Node* temp = trav->next;
        trav->next = temp->next;
        free(temp);
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    List* myList = initList();
    insertFirst(myList, 21);
    insertFirst(myList, 14);
    insertFirst(myList, 7);
    insertLast(myList, 28);
    insertPos(myList, 17, 2);
    deleteFirst(myList);
    deleteLast(myList);
    deletePos(myList, 1);
    // empty(myList);

    return 0;
}