#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For memory allocation functions

// Node structure definition
struct Node {
    int data;           // Data part of the node
    struct Node* next;  // Pointer to next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    
    // Check if node creation was successful
    if (newNode == NULL) {
        return head;  // Return original head if allocation failed
    }
    
    // Make the new node point to the current head
    newNode->next = head;
    
    // Return the new node as the new head of the list
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  // Start with empty list
    int choice, data;
    
    printf("Linked List - Insert at Beginning\n");
    printf("1. Insert node\n2. Display list\n3. Exit\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                // Insert at beginning and update head
                head = insertAtBeginning(head, data);
                printf("Node inserted successfully!\n");
                break;
                
            case 2:
                displayList(head);
                break;
                
            case 3:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
