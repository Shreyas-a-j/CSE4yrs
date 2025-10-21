#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define POOL_SIZE 1000
#define MAX_DATA_SIZE 256

typedef struct Node {
    struct Node* next;
    struct Node* prev;
    char* data;
    size_t data_size;
    int ref_count;
} Node;

typedef struct {
    char pool[POOL_SIZE * (sizeof(Node) + MAX_DATA_SIZE)];
    bool used[POOL_SIZE];
    size_t next_free;
    size_t allocated_count;
} MemoryPool;

static MemoryPool g_pool = {0};

Node* allocate_node_from_pool(size_t data_size) {
    if (data_size > MAX_DATA_SIZE) {
        fprintf(stderr, "Data size exceeds maximum limit\n");
        return NULL;
    }

    for (size_t i = g_pool.next_free; i < POOL_SIZE; i++) {
        if (!g_pool.used[i]) {
            g_pool.used[i] = true;
            g_pool.allocated_count++;
            g_pool.next_free = (i + 1) % POOL_SIZE;

            char* node_mem = g_pool.pool + i * (sizeof(Node) + MAX_DATA_SIZE);
            Node* node = (Node*)node_mem;

            memset(node, 0, sizeof(Node));
            node->data = node_mem + sizeof(Node);
            node->data_size = data_size;
            node->ref_count = 1;
            return node;
        }
    }

    // Pool exhausted - fallback to malloc
    Node* node = (Node*)malloc(sizeof(Node));
    if (node) {
        memset(node, 0, sizeof(Node));
        node->data = (char*)malloc(data_size);
        node->data_size = data_size;
        node->ref_count = 1;
    }
    return node;
}

void deallocate_node_to_pool(Node* node) {
    if (!node) return;

    size_t index = ((char*)node - g_pool.pool) / (sizeof(Node) + MAX_DATA_SIZE);
    char* node_ptr = (char*)node;

    if (node_ptr >= g_pool.pool && node_ptr < g_pool.pool + sizeof(g_pool.pool) &&
        index < POOL_SIZE && g_pool.used[index]) {
        g_pool.used[index] = false;
        g_pool.allocated_count--;
        if (index < g_pool.next_free) {
            g_pool.next_free = index;
        }
    } else {
        // Node was allocated via malloc
        free(node->data);
        free(node);
    }
}

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
    int (*compare)(const void* a, const void* b);
} AdvancedList;

AdvancedList* create_advanced_list(int (*compare_func)(const void* a, const void* b)) {
    AdvancedList* list = (AdvancedList*)malloc(sizeof(AdvancedList));
    if (list) {
        memset(list, 0, sizeof(AdvancedList));
        list->compare = compare_func;
    }
    return list;
}

bool insert_at_position(AdvancedList* list, void* data, size_t data_size, size_t position) {
    if (!list || position > list->size) return false;

    Node* new_node = allocate_node_from_pool(data_size);
    if (!new_node) return false;

    memcpy(new_node->data, data, data_size);

    if (position == 0) {
        // Insert at head
        new_node->next = list->head;
        new_node->prev = NULL;
        if (list->head) {
            list->head->prev = new_node;
        } else {
            list->tail = new_node; // First node
        }
        list->head = new_node;
    } else if (position == list->size) {
        // Insert at tail
        new_node->prev = list->tail;
        new_node->next = NULL;
        if (list->tail) {
            list->tail->next = new_node;
        } else {
            list->head = new_node; // First node
        }
        list->tail = new_node;
    } else {
        // Insert in middle - choose optimal traversal direction
        Node* current;
        if (position < list->size / 2) {
            current = list->head;
            for (size_t i = 0; i < position; i++) {
                current = current->next;
            }
        } else {
            current = list->tail;
            for (size_t i = list->size - 1; i >= position; i--) {
                current = current->prev;
            }
        }
        new_node->next = current;
        new_node->prev = current->prev;
        if (current->prev) {
            current->prev->next = new_node;
        } else {
            list->head = new_node;
        }
        current->prev = new_node;
    }
    list->size++;
    return true;
}

Node* merge_sorted_lists(Node* left, Node* right, int (*compare)(const void* a, const void* b)) {
    if (!left) return right;
    if (!right) return left;

    Node* result = NULL;
    if (compare(left->data, right->data) <= 0) {
        result = left;
        result->next = merge_sorted_lists(left->next, right, compare);
        if (result->next) result->next->prev = result;
        result->prev = NULL;
    } else {
        result = right;
        result->next = merge_sorted_lists(left, right->next, compare);
        if (result->next) result->next->prev = result;
        result->prev = NULL;
    }
    return result;
}

Node* merge_sort_recursive(Node* head, size_t length, int (*compare)(const void*, const void*)) {
    if (length <= 1) return head;

    size_t mid = length / 2;
    Node* right = head;
    for (size_t i = 0; i < mid; i++) {
        right = right->next;
    }

    Node* left = head;
    Node* temp = right->prev;
    if (temp) temp->next = NULL;
    if (right) right->prev = NULL;

    left = merge_sort_recursive(left, mid, compare);
    right = merge_sort_recursive(right, length - mid, compare);

    return merge_sorted_lists(left, right, compare);
}

void sort_advanced_list(AdvancedList* list) {
    if (!list || list->size <= 1) return;

    list->head = merge_sort_recursive(list->head, list->size, list->compare);

    Node* current = list->head;
    while (current && current->next) {
        current = current->next;
    }
    list->tail = current;
}

int int_compare(const void* a, const void* b) {
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;
    return val_a - val_b;
}

int main() {
    AdvancedList* list = create_advanced_list(int_compare);
    if (!list) {
        fprintf(stderr, "Failed to create list\n");
        return 1;
    }

    int values[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    size_t count = sizeof(values) / sizeof(values[0]);

    printf("Inserting values: ");
    for (size_t i = 0; i < count; i++) {
        insert_at_position(list, &values[i], sizeof(int), i);
        printf("%d ", values[i]);
    }
    printf("\n");

    printf("Before sorting: ");
    Node* current = list->head;
    while (current) {
        printf("%d ", *(int*)current->data);
        current = current->next;
    }
    printf("\n");

    sort_advanced_list(list);

    printf("After sorting: ");
    current = list->head;
    while (current) {
        printf("%d ", *(int*)current->data);
        current = current->next;
    }
    printf("\n");

    printf("Memory pool usage: %zu/%d nodes allocated\n", g_pool.allocated_count, POOL_SIZE);

    // Cleanup: deallocate nodes (omitted for brevity in demo)

    return 0;
}
   