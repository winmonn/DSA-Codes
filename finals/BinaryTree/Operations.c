#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* LC;
    struct node* RC;
}nodeType, *BST;

void init(BST* T){
    *T = NULL;
}

void insert(BST* T, int elem){
    BST* trav;
    for(trav = T; *trav != NULL && (*trav)->data != elem; ){
        if(elem < (*trav)->data){
            trav = &((*trav)->LC);
        } else {
            trav = &((*trav)->RC);
        }
    }
    if(*trav == NULL){
        BST temp = (BST)malloc(sizeof(nodeType));
        temp->data = elem;
        temp->LC = NULL;
        temp->RC = NULL;
        *trav = temp;
    }
}

void inOrder(BST T){
    if(T != NULL){
        inOrder(T->LC);
        printf("%d ", T->data);
        inOrder(T->RC);
    }
}

void preOrder(BST T){
    if(T != NULL){
        printf("%d ", T->data);
        preOrder(T->LC);
        preOrder(T->RC);
    }
}

void postOrder(BST T){
    if(T != NULL){
        postOrder(T->LC);
        postOrder(T->RC);
        printf("%d ", T->data);
    }
}

void deleteNode(BST* T, int elem){
    BST* trav;
    for(trav = T; *trav != NULL && (*trav)->data != elem; ){
        if(elem < (*trav)->data){
            trav = &((*trav)->LC);
        } else {
            trav = &((*trav)->RC);
        }
    }
    if(*trav != NULL){
        if((*trav)->LC == NULL && (*trav)->RC == NULL){
            *trav = NULL;
            free(*trav);
        } else if((*trav)->LC != NULL && (*trav)->RC == NULL){
            *trav = (*trav)->LC;
        } else if((*trav)->LC == NULL && (*trav)->RC != NULL){
            *trav = (*trav)->RC;
        } else {
            BST temp = *trav;
            trav = &((*trav)->LC);
            while((*trav)->RC != NULL){
                trav = &((*trav)->RC);
            }
            temp->data = (*trav)->data;
            *trav = ((*trav)->LC);
        }
    }
}

int main() {
    BST T;
    init(&T);
    insert(&T, 7);
    insert(&T, 2);
    insert(&T, 5);
    insert(&T, 11);
    insert(&T, 3);
    insert(&T, 9);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");
    deleteNode(&T, 7);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");

    return 0;
}