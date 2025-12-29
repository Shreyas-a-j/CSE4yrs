#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

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
Node *insertfront(Node *head);

void main()
{
    Node *head = NULL;
    int ch;
    while(1){
        printf("\nEnter the choice:\n 1: insert n students\n 2: insert front\n 3: insert rear\n 4: delete front\n 5: delete rear\n 6: Display\n 7: exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insertnNode(head); break;
            case 2: head = insertfront(head); break;
            case 3:
            case 4:
            case 5:
            case 6:
            case 7: exit(0);
        }
    }
}
Node *create()
{
    Node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the name: ");
    scanf("%s",temp->name);
    fflush(stdin);
    printf("\nEnter the usn: ");
    scanf("%s",temp->usn);
    fflush(stdin);
    printf("\nEnter the Branch: ");
    scanf("%s",temp->dep);
    fflush(stdin);
    printf("\nEnter sem: ");
    scanf("%d",&temp->sem);
    fflush(stdin);
    printf("\nEnter phno: ");
    scanf("%s",temp->phno);
    fflush(stdin);
    temp->next = NULL;
    return temp;
}
Node *insertnNode(Node *head)
{
    int n,i;
    Node *cur;
    cur = head;
    printf("\nEnter n: ");
    scanf("%d",&n);
    fflush(stdin);
    for(i=0;i<n;i++){
        head = insertfront(head);
    }
    return head;

}
Node *insertfront(Node *head)
{
    Node *temp;
    temp = create();
    if(head == NULL){
        head = temp;
    } else
    {
        temp->next = head;
        head=temp;
    }
    return head;
}
