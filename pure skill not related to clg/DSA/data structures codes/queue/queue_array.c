#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} ArrayQueue;

// Initialize queue
void initQueue(ArrayQueue* q) {
    q->front = 0;
    q->rear = -1; // our queue is empty
    q->size = 0;
}

// Check if queue is empty
bool isEmpty(ArrayQueue* q) {
    return q->size == 0;
}

// Check if queue is full
bool isFull(ArrayQueue* q) {
    return q->size == MAX_SIZE;
}

// Enqueue operation - inserting an element at the rear end
bool enqueue(ArrayQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return false;
    }

    q->rear++; // rear = 0;
    q->data[q->rear] = value;
    q->size++;
    return true;
}

// Dequeue operation
int dequeue(ArrayQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        q->front = 0;
        q->rear = -1;
        return -1; // Indicate queue is empty
    }

    int value = q->data[q->front]; // 10
    q->front++;
    q->size--;
 
    return value;
}

// Peek operation
int peek(ArrayQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek\n");
        return -1; // Indicate queue is empty
    }
    return q->data[q->front];
}

// Display queue
void display(ArrayQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]); // 10, 20, 30 ,40, 50
    }
    printf("\n");
}

// get current size
int getSize(ArrayQueue* q) {
    return q->size;
}

int main() {
    ArrayQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q); // 10, 20, 30, 40, 50

    printf("Dequeued: %d\n", dequeue(&q)); // 10
    printf("Dequeued: %d\n", dequeue(&q)); // 20
    display(&q); // 30, 40, 50
    printf("Front element: %d\n", peek(&q)); // 30
    display(&q); // 30, 40, 50

    printf("Current size: %d\n", getSize(&q)); // 3

    return 0;
}
