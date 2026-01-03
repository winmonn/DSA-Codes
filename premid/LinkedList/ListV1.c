#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int count;
} List;

List initList() {
    List L;
    L.head = NULL;
    L.count = 0;
    return L;
}

List empty(List L) {
    Node* trav;
    Node* temp = NULL;

    for (trav = L.head; trav != NULL; ) {
        L.head = trav->next;
        temp = trav;
        trav = L.head;
        free(temp);
    }

    L.head = NULL;
    L.count = 0;
    return L;
}

List insertFirst(List L, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = L.head;
        L.head = newNode;
        L.count++;
    }
    return L;
}

List insertLast(List L, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;

        if (L.head == NULL) {
            L.head = newNode;
        } else {
            Node* trav;
            for (trav = L.head; trav->next != NULL; trav = trav->next) { }
            trav->next = newNode;
        }

        L.count++;
    }
    return L;
}

List insertPos(List L, int data, int index) {
    if (index > 0 && index < L.count) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode != NULL) {
            newNode->data = data;
            newNode->next = NULL;

            int pos = 0;
            Node* trav;
            for (trav = L.head; trav->next != NULL && pos != index - 1; trav = trav->next, pos++) { }

            newNode->next = trav->next;
            trav->next = newNode;
            L.count++;
        }
    } else if (index == 0) {
        L = insertFirst(L, data);
    } else if (index == L.count) {
        L = insertLast(L, data);
    } else {
        printf("Index is invalid.\n");
    }

    return L;
}

List deleteFirst(List L) {
    if (L.head != NULL) {
        Node* temp = L.head;
        L.head = temp->next;
        free(temp);
        L.count--;
    } else {
        printf("List is empty.\n");
    }
    return L;
}

List deleteLast(List L) {
    if (L.head == NULL) {
        printf("List is empty.\n");
        return L;
    }

    if (L.head->next == NULL) {
        free(L.head);
        L.head = NULL;
        L.count--;
        return L;
    }

    Node* trav = L.head;
    Node* temp = trav->next;

    for (; temp->next != NULL; trav = trav->next, temp = temp->next) { }

    trav->next = NULL;
    free(temp);
    L.count--;

    return L;
}

List deletePos(List L, int index) {
    if (index == 0) {
        L = deleteFirst(L);
    } else if (index > 0 && index < L.count) {
        Node* trav;
        int pos = 0;

        for (trav = L.head; trav->next != NULL && pos != index - 1; trav = trav->next, pos++) { }

        Node* temp = trav->next;
        trav->next = temp->next;
        free(temp);
        L.count--;
    } else {
        printf("Invalid index.\n");
    }

    return L;
}

int main() {
    List myList = initList();

    myList = insertFirst(myList, 21);
    myList = insertFirst(myList, 14);
    myList = insertFirst(myList, 7);

    myList = insertLast(myList, 28);
    myList = insertPos(myList, 17, 2);

    myList = deleteFirst(myList);
    myList = deleteLast(myList);
    myList = deletePos(myList, 1);

    myList = empty(myList);

    return 0;
}
