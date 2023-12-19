#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef void (*ForEachFunction)(struct Node*);

struct List {
    struct Node* root;
    ForEachFunction foreach;
    void (*add)(struct List* list, int data);
    void (*remove)(struct List* list, int data);
    
};

void printCallback(struct Node* node) {
}

struct List* createList() {
    struct List* newList = malloc(sizeof(struct List));
    if (newList != NULL) {
        newList->root = NULL;
        newList->foreach = printCallback;
        newList->add = NULL;
        newList->remove = NULL;
    }
    return newList;
}

void addToList(struct List* list, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = list->root;
        list->root = newNode;
    }
}

void removeFromList(struct List* list, int data) {
    struct Node* current = list->root;
    struct Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            list->root = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

void foreach(struct List* list) {
    struct Node* current = list->root;
    while (current != NULL) {
        list->foreach(current);
        current = current->next;
    }
}

void freeList(struct List* list) {
    struct Node* current = list->root;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    struct List* myList = createList();

    myList->add = addToList;
    myList->remove = removeFromList;

    myList->add(myList, 10);
    myList->add(myList, 20);
    myList->add(myList, 30);

    if (myList->foreach != NULL) {
        printf("Lista antes da remoção: ");
        foreach(myList);  
        printf("\n");
    }

    myList->remove(myList, 20);

    if (myList->foreach != NULL) {
        printf("Lista após a remoção: ");
        foreach(myList);  
        printf("\n");
    }

    freeList(myList);

    return 0;
}
