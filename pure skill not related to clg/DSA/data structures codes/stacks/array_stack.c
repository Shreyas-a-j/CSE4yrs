#include<stdio.h>
#include<stdlib.h>
#define MAX 100 // Max stack size

typedef struct {
    int data[MAX];
    int top;
} ArrayStack;
 
// Initialize stack
void initStack(ArrayStack* s) {
    s->top = -1; // because our stack is empty and the is no top ele; 
}

// Push - add an element to the stack 
int push(ArrayStack* s, int value) {
    if (s->top == MAX - 1) { // if s->top = 99;
        printf("Stack overflow\n");
        return 0;
    }
    s->data[++(s->top)] = value; // incrementing top = top + 1 and storing 10 s->data[0] = 10;
    return 1;
}

// Pop - remove and return the top element of the stack
int pop(ArrayStack* s) {
    if (s->top < 0) { 
        printf("Stack Underflow\n");
        return -1; // Indicate stack is empty
    }
    return s->data[(s->top)--]; // returning the top element and decrementing top = top - 1;
}

//Peek - return the top element without removing it
int peek(ArrayStack* s) {
    if (s->top < 0) {
        printf("Stack is empty\n");
        return -1; // Indicate stack is empty
    }
    return s->data[s->top];
}

// Display stack 
void display(ArrayStack* s) {
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    ArrayStack s;
    initStack(&s);
    push(&s, 10); push(&s, 20); push(&s, 30); push(&s, 40); push(&s, 50); // 10, 20, 30, 40, 50
    display(&s); // 10, 20, 30, 40, 50
    printf("Popped element is %d\n", pop(&s)); // 50;
    printf("Top element is %d\n", peek(&s)); // 40
    display(&s); // 10, 20, 30, 40
    return 0;
}