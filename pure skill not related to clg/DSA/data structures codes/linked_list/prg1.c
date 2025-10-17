#include <stdio.h>      // For input/output functions like printf, scanf
#include <stdlib.h>     // For memory allocation functions like malloc, free

// Define the structure for a node in the linked list
struct Node {
    int data;           // Integer data stored in the node
    struct Node* next;  // Pointer to the next node in the list
};

// Function to create a new node
struct Node* createNode(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    // Initialize the new node
    newNode->data = data;    // Set the data value
    newNode->next = NULL;    // Set next pointer to NULL (end of list)
    
    return newNode;          // Return pointer to the new node
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;  // Create a temporary pointer starting from head
    
    // Check if the list is empty
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Linked List: ");
    
    // Traverse the list until we reach the end (NULL)
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // Print current node's data
        temp = temp->next;             // Move to the next node
    }
    printf("NULL\n");  // Indicate end of list
}

int main() {
    struct Node* head = NULL;  // Initialize head pointer to NULL (empty list)
    
    // Create some nodes manually
    head = createNode(10);              // Create first node with data 10
    head->next = createNode(20);        // Create second node with data 20
    head->next->next = createNode(30);  // Create third node with data 30
    
    // Display the created list
    displayList(head);
    
    return 0;
}
