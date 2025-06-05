#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "yuutil.h"

struct stack
{
    int size;
    int top;
    int* container;
};

struct stack init(int size) {
    struct stack s;
    s.size = size;
    s.top = -1;
    s.container = (int*)malloc(size* sizeof(int));
    if(s.container==NULL) {
        println("Malloc failed");
    }
    return s;
}

bool isEmpty(struct stack *s) {
    if(s->top==-1) {
        return true;
    }
    return false;
}

bool isFull(struct stack *s) {
    if(s->top==s->size-1) {
        return true;
    }
    return false;
}

int peek(struct stack *s) {
    if(isEmpty(s)) {
        println("Stack empty");
        return -1;
    }
    return s->container[s->top];
}

void display(struct stack *s) {
    for(int i = 0; i<=s->top;i++) {
        printf("%d\t", s->container[i]);
    }
    printf("\n");
}

void push(struct stack *s, int value) {
    if(isFull(s)) {
        println("Stack full");
        return;
    }
    s->container[s->top+1] = value;
    s->top++;
}

int pop(struct stack *s) {
    if(isEmpty(s)) {
        println("Stack empty");
        return -1;
    }
    int k = s->container[s->top];
    s->top--;
    return k;
}

void freeStack(struct stack *s) {
    free(s->container);
}

int main() {
    struct stack s = init(7);
    isEmpty(&s) ? println("Empty") : println("Not empty");
    push(&s, 57);
    push(&s, 88);
    display(&s);
    push(&s, 193);
    println("%d", peek(&s));
    println("%d", pop(&s));
    println("%d", peek(&s));
    push(&s, 1);
    push(&s, 2);
    push(&s, 4);
    push(&s, 26);
    push(&s, 69);
    display(&s);
    push(&s, 133);
    push(&s, 101);

    freeStack(&s);
    return 0;
}