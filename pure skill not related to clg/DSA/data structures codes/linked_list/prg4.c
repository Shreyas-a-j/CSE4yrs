#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For memory allocation and free function

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

// Function to delete node at nth position (1-based indexing)
struct Node* deleteAtPosition(struct Node* head, int position) {
    // Check for invalid position
    if (position < 1) {
        printf("Invalid position! Position should be >= 1\n");
        return head;
    }
    
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return head;
    }
    
    // Special case: Delete first node (position 1)
    if (position == 1) {
        struct Node* temp = head;    // Store current head
        head = head->next;           // Move head to next node
        free(temp);                  // Free memory of deleted node
        printf("Node at position 1 deleted successfully!\n");
        return head;                 // Return new head
    }
    
    // Find the node at (position-1)th location
    struct Node* temp = head;
    
    // Traverse to (position-1)th node
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    // Check if position is beyond the list length
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is beyond the list length\n", position);
        return head;
    }
    
    // Store the node to be deleted
    struct Node* nodeToDelete = temp->next;
    
    // Update the links: bypass the node to be deleted
    temp->next = nodeToDelete->next;
    
    // Free the memory of the deleted node
    free(nodeToDelete);
    
    printf("Node at position %d deleted successfully!\n", position);
    return head;
}

// Function to insert node at beginning (for testing)
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    
    newNode->next = head;
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
    
    printf("Linked List - Delete at nth Position\n");
    printf("1. Insert node (at beginning)\n");
    printf("2. Delete node at position\n");
    printf("3. Display list\n");
    printf("4. Count nodes\n");
    printf("5. Exit\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("Node inserted successfully!\n");
                break;
                
            case 2:
                if (head == NULL) {
                    printf("List is empty! Nothing to delete.\n");
                } else {
                    printf("Current list has %d nodes\n", countNodes(head));
                    printf("Enter position to delete (1-based): ");
                    scanf("%d", &position);
                    head = deleteAtPosition(head, position);
                }
                break;
                
            case 3:
                displayList(head);
                break;
                
            case 4:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
                
            case 5:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
