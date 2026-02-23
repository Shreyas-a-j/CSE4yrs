#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3

int stack[MAX_SIZE];
int top = -1;

void push(int ele);
int pop();
void palendrome();
void display();

void main()
{
    printf("Enter Your choice: \n");
    int ch;
    while(1){
        printf("\n1: Push element \n2: pop element \n3: cheeck palendrome \n4: Stack Status \n5: exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: int ele;
                    printf("\nEnter the ele to Push: ");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2: int p = pop();
                    printf("%d",p);
                    break;
            case 3: palendrome();
                    break;
            case 4: display();
                    break;
            case 5: return;
            default: return;

        }
    }
}
void push(int ele) {
    if(top == MAX_SIZE-1) {
        printf("\nStack Overflow\n");
        return;
    }else{
        top++;
        stack[top] = ele;
        printf("\nPushed %d", ele);
    }
}
int pop() {
    if(top == -1) {
        printf("\nStack Underflow\n");
        return -1;
    }
    int ele = stack[top];
    top--;
    return ele;
}
void display()
{
    if(top == -1){
        printf("\nStack Underflow\n");
        return;
    }
    for(int i=top; i>=0; i--){
            printf("%d\t",stack[i]);
    }

}
void palendrome() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    int copy[MAX_SIZE];
    int n = top + 1;
    for(int i = 0; i < n; i++) {
        copy[i] = stack[i];
    }
    for(int i = 0; i < n/2; i++) {
        if(stack[i] != stack[n-1-i]) {
            printf("\nNot Palindrome\n");
            return;
        }
    }
    printf("\nIs Palindrome\n");
}
