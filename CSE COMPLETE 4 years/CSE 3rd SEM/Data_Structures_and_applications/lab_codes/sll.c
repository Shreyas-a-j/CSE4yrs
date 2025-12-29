#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct node
{
    char name[25];
    char usn[11];
    char dep[10];
    int sem;
    int phno[10];
    struct node *next;
};

typedef struct node Node;

Node *create();
Node *insertnNode(Node *head);
void countnodes(Node *head);
Node *insertrear(Node *head);
Node *deleterear(Node *head);
Node *insertfront(Node *head);
Node *deletefront(Node *head);
void display(Node *head);

void main()
{
    Node *head = NULL;
    int ch;
    while(1){
        printf("\nEnter the choice:\n 1: insert n students\n 2: insert front\n 3: insert rear\n 4: delete front\n 5: delete rear\n 6: Display\n 7: exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insertnNode(head); break;
            case 2: head = insertfront(head); break;
            case 3: head = insertrear(head); break;
            case 4: head = deletefront(head); break;
            case 5: head = deleterear(head); break;
            case 6: display(head); break;
            case 7: exit(0);
        }
    }
}
