#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "yuutil.h"

struct queue
{
    int size;
    int front;
    int rear;
    int* container;
};

struct queue init(int size) {
    struct queue q;
    q.size = size + 1;
    q.front = 0;
    q.rear = 0;
    q.container = (int*)malloc(size*sizeof(int));
    return q;
}

bool isEmpty(struct queue *q) {
    return q->rear == q->front;
}

bool isFull(struct queue *q) {
    return (q->rear+1) % q->size == q->front;
}

int peek(struct queue *q) {
    return q->container[q->front];
}

void display(struct queue *q) {
    if(isEmpty(q)) {
        println("Queue is empty");
        return;
    }
    int i = q->front;
    while (i!=q->rear){
        printf("%d\t", q->container[i]);
        i = (i+1) % q->size;
    }
    printf("\n");
}

void enqueue(struct queue *q, int value) {
    if(isFull(q)) {
        println("Queue is full");
        return;
    }
    q->container[q->rear] = value;
    q->rear = (q->rear+1) % q->size;
}

int dequeue(struct queue *q) {
    if(isEmpty(q)) {
        println("Queue is empty");
        return -1;
    }
    int k = q->container[q->front];
    q->front = (q->front+1) % q->size;
    return k;
}

void freeQueue(struct queue *q) {
    free(q->container);
}

int main() {
    struct queue q = init(7);
    isEmpty(&q) ? println("true") : println("false");
    enqueue(&q, 20);
    enqueue(&q, 12);
    enqueue(&q, 24);
    display(&q);
    println("%d", dequeue(&q));
    display(&q);
    enqueue(&q, 6);
    enqueue(&q, 11);
    enqueue(&q, 3);
    enqueue(&q, 28);
    enqueue(&q, 50);
    display(&q);
    enqueue(&q, 16);
    display(&q);
    println("%d", dequeue(&q));
    enqueue(&q, 21);
    display(&q);

    freeQueue(&q);
    return 0;
}