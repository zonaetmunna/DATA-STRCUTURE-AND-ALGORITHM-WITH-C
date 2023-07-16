#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to search for an element in the linked list
int searchLinkedList(struct Node* head, int target) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            return 1; // Element found
        }
        current = current->next;
    }

    return 0; // Element not found
}

int main() {
    // Create nodes
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to nodes
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;

    // Connect nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Set the head of the linked list
    struct Node* head = node1;

    // Search for target element
    int target = 2;
    int isFound = searchLinkedList(head, target);

    // Print the result
    if (isFound) {
        printf("%d is found in the linked list.\n", target);
    } else {
        printf("%d is not found in the linked list.\n", target);
    }

    // Free memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

