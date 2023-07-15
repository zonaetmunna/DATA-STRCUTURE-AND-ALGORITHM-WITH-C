
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};


// Function to traverse the linked list and print its elements
void traverseLinkedList(struct Node* head) {
    struct Node* current = head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
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

    // Traverse and print the linked list
    traverseLinkedList(head);

    // Free memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

//pseudo code
/*
Structure Node:
    data
    next

Function traverseLinkedList(head):
    current = head

    Print "Linked List: "
    while current is not NULL:
        Print current.data
        current = current.next

Function main():
    node1 = Allocate memory for Node
    node2 = Allocate memory for Node
    node3 = Allocate memory for Node

    node1.data = 1
    node2.data = 2
    node3.data = 3

    node1.next = node2
    node2.next = node3
    node3.next = NULL

    head = node1

    traverseLinkedList(head)

    Free memory for node1
    Free memory for node2
    Free memory for node3




*/


