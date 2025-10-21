#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define TaBLE_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.75

// Node for linked list (chaining)
typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

// Hash table structure
typedef struct {
    Node** buckets;
    int size;
    int count;
} HashTable;

// Hash function (djb2 algorithm for strings)
unsigned long hash_function(const char* str, int table_size) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % table_size;
}

// Create new node
Node* create_node(const char* key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;
    return node;
}

// Initialize hash table
HashTable* create_hash_table(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (!table) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    table->size = size;
    table->count = 0;
    table->buckets = (Node**)calloc(size, sizeof(Node*));
    if (!table->buckets) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return table;
}

//calculate load factor
float load_factor(HashTable* table) {
    return (float)table->count / table->size;
}

// Insert key-value  pair
bool insert(HashTable* table, const char* key, int value) {
    unsigned long index = hash_function(key, table->size);
    Node* current = table->buckets[index];

    // Check if key already exists, update value
    while (current) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            printf("Key '%s' updated with value %d\n", key, value);
            return true;
        }
        current = current->next;
    }

    // Insert new node at the beginning of the linked list
    Node* newNode = create_node(key, value);
    if (!newNode) {
        return false;
    }
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
    table->count++;

    printf("Inserted: %s = %d at bucket[%lu]\n", key, value, index);
    return true;
}

// Search for a key
bool search(HashTable* table, const char* key, int* value) {
    unsigned long index = hash_function(key, table->size);
    Node* current = table->buckets[index];

    while (current) {
        if (strcmp(current->key, key) == 0) {
            *value = current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Delete key 
bool delete(HashTable* table, const char* key) {
    unsigned long index = hash_function(key, table->size);
    Node* current = table->buckets[index];
    Node* prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }
            free(current->key);
            free(current);
            table->count--;
            printf("Key '%s' deleted\n", key);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// Display hash table
void display(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        Node* current = table->buckets[i];
        if (current) {
            printf("Bucket[%d]: ", i);
            while (current) {
                printf("(%s: %d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

// Free hash table
void free_hash_table(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        Node* current = table->buckets[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

// Demonstration
int main() {
    HashTable* table = create_hash_table(TaBLE_SIZE);

    insert(table, "apple", 1);
    insert(table, "banana", 2);
    insert(table, "orange", 3);
    insert(table, "grape", 4);
    insert(table, "melon", 5);

    display(table);

    int value;
    if (search(table, "banana", &value)) {
        printf("Found banana: %d\n", value);
    } else {
        printf("banana not found\n");
    }

    delete(table, "orange");
    display(table);

    free_hash_table(table);
    return 0;
}