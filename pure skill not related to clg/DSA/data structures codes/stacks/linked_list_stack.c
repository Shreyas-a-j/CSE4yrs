#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} LinkedStack;

// Initialize stack
void initStack(LinkedStack* s) {
    s->top = NULL; 
    s->size = 0;
}

// Push - add an element to the stack
void push(LinkedStack* s, int value) {
    Node* temp = (Node*)malloc(sizeof(Node)); 
    if (!temp) { // if 0 then false and in all other cases true
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = value;
    temp->next = s->top;
    s->top = temp;
    s->size++; 
}

// Pop - remove and return the top element of the stack
int pop(LinkedStack* s) {
    if (!s->top) {
        printf("Stack Underflow!\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;
    return value;
}

// Peek (top) - return the top element without removing it
int peek(LinkedStack* s) {
    if (!s->top) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->data; 
}

// Display stack
void display(LinkedStack* s) {
    printf("Stack: ");
    Node* curr = s->top;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    LinkedStack s;
    initStack(&s);
    push(&s, 40); push(&s, 50); push(&s, 60); push(&s, 70); // 70, 60, 50, 40
    display(&s); // 70, 60, 50, 40
    printf("Popped element is %d\n", pop(&s)); // 70;
    printf("Top element is %d\n", peek(&s)); // 60; 
    display(&s); // 60, 50, 40
    return 0;
}