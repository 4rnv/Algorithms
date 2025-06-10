#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "yuutil.h"

struct Node {
    int data;
    struct Node *next; // pointer to the next node
};

struct Node *init() {
    struct Node *head = NULL;
    // return head;
    return NULL;
}

int length(struct Node *head) {
    struct Node *current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void addAtHead(struct Node **headRef, int value) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = value;
    new->next = *headRef;
    *headRef = new; // headRef is pointing towards the head Node
}

void addAtTail(struct Node **headRef, int value) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;
    struct Node *current = *headRef;
    if (current == NULL) { // list is empty
        *headRef = new;
    }
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}

void display(struct Node *head) {
    struct Node *current = head;
    if (current == NULL) {
        println("List is empty");
        return;
    }
    printf("\n");
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

bool search(struct Node *head, int key) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

struct Node *reverse(struct Node *head) {
    struct Node *copy = init();
    struct Node *current = head;
    while (current != NULL) {
        addAtHead(&copy, current->data);
        current = current->next;
    }
    return copy;
}

void deleteFromHead(struct Node **headRef) {
    if (*headRef == NULL) {
        println("List is empty");
        return;
    }
    struct Node *temp = *headRef;
    *headRef = temp->next;
    free(temp);
}

void deleteFromTail(struct Node **headRef) {
    if (*headRef == NULL) {
        println("List is empty");
        return;
    }
    if ((*headRef)->next == NULL) { // only one node in list
        free(*headRef);
        *headRef = NULL;
        *headRef = NULL;
        return;
    }
    struct Node *current = *headRef;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void deleteByValue(struct Node **headRef, int key) {
    struct Node *current = *headRef;
    struct Node *prev = NULL;
    if (current != NULL && current->data == key) {
        *headRef = current->next;
        free(current);
        println("Deleted node with value %d", key);
        return;
    }
    while (current != NULL && current->data != key) { //if there is a match the loop will break and jump to line 132
        prev = current;
        current = current->next;
    }

    //reached the end of list with no match
    if(current==NULL) {
        println("Node with value %d not found in list", key);
        return;
    }

    prev->next = current->next;
    free(current);
    println("Deleted node with value %d", key);
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp;
    while(current->next!=NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
}

int main() {
    struct Node *list = init();
    addAtTail(&list, 3);
    addAtTail(&list, 18);
    addAtTail(&list, 47);
    println("%d", length(list));
    display(list);
    addAtHead(&list, 88);
    display(list);
    addAtTail(&list, 52);
    display(list);
    search(list, 88) ? println("true") : println("false");
    display(reverse(list));
    display(list);
    deleteFromHead(&list);
    display(list);
    deleteFromTail(&list);
    display(list);
    addAtTail(&list, 15);
    addAtHead(&list, 35);
    addAtTail(&list, 24);
    addAtHead(&list, 76);
    addAtTail(&list, 89);
    display(list);
    deleteByValue(&list, 47);
    display(list);

    freeList(list);
    return 0;
}