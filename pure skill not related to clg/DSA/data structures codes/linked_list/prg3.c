#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For memory allocation functions

// Node structure definition
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
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

// Function to insert node at nth position (1-based indexing)
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    // Check for invalid position
    if (position < 1) {
        printf("Invalid position! Position should be >= 1\n");
        return head;
    }
    
    // Create new node
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    
    // Special case: Insert at position 1 (beginning)
    if (position == 1) {
        newNode->next = head;  // Point new node to current head
        return newNode;        // Return new node as new head
    }
    
    // Find the position to insert
    struct Node* temp = head;
    
    // Traverse to (position-1)th node
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    // Check if position is beyond the list length
    if (temp == NULL) {
        printf("Position %d is beyond the list length\n", position);
        free(newNode);  // Free the allocated memory
        return head;
    }
    
    // Insert the new node
    newNode->next = temp->next;  // New node points to the next node
    temp->next = newNode;        // Previous node points to new node
    
    return head;  // Return original head (unchanged)
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

// Function to count nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    printf("Linked List - Insert at nth Position\n");
    printf("1. Insert node at position\n2. Display list\n3. Count nodes\n4. Exit\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                
                // Insert at specified position
                head = insertAtPosition(head, data, position);
                break;
                
            case 2:
                displayList(head);
                break;
                
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
                
            case 4:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
