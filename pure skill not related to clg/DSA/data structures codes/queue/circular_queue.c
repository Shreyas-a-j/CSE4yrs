// circular_queue.c


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

// Initialize circular queue
void initCircularQueue(CircularQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = MAX_SIZE;
}

// check if empty
bool isEmptyCircular(CircularQueue* q) {
    return q->size == 0;
}

// check if full
bool isFullCircular(CircularQueue* q) {
    return q->size == q->capacity;
}

// Enqueue with circular wraparound
bool enqueueCircular(CircularQueue* q, int value) {
    if (isFullCircular(q)) {
        printf("Circular Queue Overflow! Cannot enqueue %d\n", value);
        return false;
    }

    q->rear = (q->rear + 1) % q->capacity; // Circular increment using modulo
    q->data[q->rear] = value;
    q->size++;

    printf("Enqueued %d at position %d\n", value, q->rear);
    return true;
}

//Dequeue with circular logic
int dequeueCircular(CircularQueue* q) {
    if (isEmptyCircular(q)) {
        printf("Circular Queue Underflow! Cannot dequeue\n");
        return -1; // Indicate queue is empty
    }

    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity; // Circular increment using modulo
    q->size--;

    printf("Dequeued %d from position %d\n", value, (q->front - 1 + q->capacity) % q->capacity);
    return value;
}

// Peek front
int peekCircular(CircularQueue* q) {
    if (isEmptyCircular(q)) {
        printf("Circular Queue is empty\n");
        return -1; // Indicate queue is empty
    }
    return q->data[q->front];
}

//Display circular queue
void displayCircularQueue(CircularQueue* q) {
    if (isEmptyCircular(q)) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity; // Calculate the correct index using modulo
        printf("%d ", q->data[index]);
    }
    printf("\n");
    printf("Front at index %d, Rear at index %d, and size %d\n", q->front, q->rear, q->size);
}

int main() {
    CircularQueue cq;
    initCircularQueue(&cq);

    enqueueCircular(&cq, 10);
    enqueueCircular(&cq, 20);
    enqueueCircular(&cq, 30);
    enqueueCircular(&cq, 40);
    enqueueCircular(&cq, 50); // Queue is now full
    displayCircularQueue(&cq); // 10, 20, 30, 40, 50

    printf("Dequeued element: %d\n", dequeueCircular(&cq));
    printf("Dequeued element: %d\n", dequeueCircular(&cq));
    displayCircularQueue(&cq); // 30, 40 ,50

    enqueueCircular(&cq, 60);
    enqueueCircular(&cq, 70); // Should wrap around
    displayCircularQueue(&cq);

    printf("Front element is %d\n", peekCircular(&cq));

    return 0;
}