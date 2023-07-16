
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at a specific position in the linked list
void insertNode(struct Node** head, int position, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (position == 0) {
        // Insert at the beginning of the list
        newNode->next = *head;
        *head = newNode;
    } else {
        // Insert at a specific position
        struct Node* current = *head;
        int count = 0;

        while (count < position - 1 && current->next != NULL) {
            current = current->next;
            count++;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert nodes at different positions
    insertNode(&head, 0, 10); // Insert 10 at the beginning
    insertNode(&head, 1, 20); // Insert 20 at position 1
    insertNode(&head, 2, 30); // Insert 30 at position 2

    // Print the updated linked list
    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}
