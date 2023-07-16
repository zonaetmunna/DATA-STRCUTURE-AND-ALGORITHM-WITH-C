
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the linked list
void traverseLinkedList(struct Node* head) {
    struct Node* current = head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

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

// Function to insert a new node at the beginning of the linked list
void insertNodeAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node with a given value from the linked list
void deleteNode(struct Node** head, int target) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    // If the head node contains the target value
    if (current != NULL && current->data == target) {
        *head = current->next;
        free(current);
        return;
    }

    // Search for the target value in the linked list
    while (current != NULL && current->data != target) {
        prev = current;
        current = current->next;
    }

    // If the target value is found, remove the node from the linked list
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertNodeAtBeginning(&head, 30);
    insertNodeAtBeginning(&head, 20);
    insertNodeAtBeginning(&head, 10);

    // Traverse and print the linked list
    traverseLinkedList(head);

    // Search for an element
    int target = 20;
    if (searchLinkedList(head, target)) {
        printf("%d is found in the linked list.\n", target);
    } else {
        printf("%d is not found in the linked list.\n", target);
    }

    // Delete a node
    deleteNode(&head, 20);

    // Traverse and print the updated linked list
    traverseLinkedList(head);

    return 0;
}
