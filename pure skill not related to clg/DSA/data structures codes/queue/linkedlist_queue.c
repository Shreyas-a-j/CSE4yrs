#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} LinkedQueue;

// Create new node
Node* create(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Initialize linked queue
void initLinkedQueue(LinkedQueue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Check if empty
bool isEmptyLinkedQueue(LinkedQueue* q) {
    return q->size == 0;
}

// Enqueue
void enqueueLinkedQueue(LinkedQueue* q, int value) {
    Node* newNode = create(value);
    if (isEmptyLinkedQueue(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->size++;
}

// Dequeue
int dequeueLinkedQueue(LinkedQueue* q) {
    if (isEmptyLinkedQueue(q)) {
        printf("Linked Queue Underflow! Cannot dequeue\n");
        return -1; // Indicate queue is empty
    }

    Node* temp = q->front;
    int value = temp->data; // 10
    q->front = q->front->next;
    free(temp);
    q->size--;

    if (isEmptyLinkedQueue(q)) {
        q->rear = NULL;
    }

    return value;
}

// Peek front
int peekLinkedQueue(LinkedQueue* q) {
    if (isEmptyLinkedQueue(q)) {
        printf("Linked Queue is empty\n");
        return -1; // Indicate queue is empty
    }
    return q->front->data; 
}

// Display linked queue
void displayLinkedQueue(LinkedQueue* q) {
    if (isEmptyLinkedQueue(q)) {
        printf("Linked Queue is empty\n");
        return;
    }

    printf("Linked Queue: ");
    Node* current = q->front;
    while (current) {
        printf("%d ", current->data); // 10, 20, 30
        current = current->next;
    }
    printf("\n");
    printf("Front at %p, Rear at %p, and size %d\n", (void*)q->front, (void*)q->rear, q->size);
}

// free entire queue
void freeQueue(LinkedQueue* q)
{
    while (!isEmptyLinkedQueue(q)) {
        dequeueLinkedQueue(q);
    }
}


int main() {
    LinkedQueue q;
    initLinkedQueue(&q);

    enqueueLinkedQueue(&q, 10);
    enqueueLinkedQueue(&q, 20);
    enqueueLinkedQueue(&q, 30);
    displayLinkedQueue(&q); // 10, 20 ,30

    printf("Dequeued element: %d\n", dequeueLinkedQueue(&q)); // 10

    printf("Front element is %d\n", peekLinkedQueue(&q)); // 20

    return 0;
}