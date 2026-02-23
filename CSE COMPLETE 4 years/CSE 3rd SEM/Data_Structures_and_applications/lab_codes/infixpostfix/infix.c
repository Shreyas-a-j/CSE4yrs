#include<stdio.h>
#include<ctype.h>
#define max 100

char stack[100];
int top = -1;

void push(char ele)
{
    stack[++top] = ele;
}
int pop()
{
    return stack[top--];
}
int precedence(char c)
{
    if(c == '^'){
        return 3;
    }else if(c == '*' || c == '/')
    {
        return 2;
    }else if(c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}
int main()
{
    char infix[max], postfix[max];
    int i=0, j=0;
    char c,temp;

    printf("\nEnter the infix expression: ");
    scanf("%s",infix);

    while((c = infix[i++])!='\0')
    {
        if(isalnum(c)){
            postfix[j++]=c;
        }
        else if(c == '('){
            push(c);
        }
        else if(c == ')'){
            while(stack[top]!='('){
                postfix[j++] = pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top]) >= precedence(c)){
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while(top!=-1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    printf("\nThe Postfix Expression is: ");
    printf("%s",postfix);
    return 0;
}
