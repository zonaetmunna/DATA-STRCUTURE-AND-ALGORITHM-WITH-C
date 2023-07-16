
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to push data into the stack
void push(struct Node** top, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *top;
    *top = newNode;
}

// Function to traverse and print the stack
void traverseStack(struct Node* top) {
    printf("Stack: ");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to pop data from the stack
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow: Cannot delete from an empty stack\n");
        return;
    }

    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
}

int main() {
    struct Node* stackTop = NULL;

    // Insert data into the stack
    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);

    // Traverse and print the stack
    traverseStack(stackTop);

    // Delete the top element
    pop(&stackTop);

    // Traverse and print the updated stack
    traverseStack(stackTop);

    return 0;
}
