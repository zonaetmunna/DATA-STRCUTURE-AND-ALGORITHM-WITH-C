
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

    // Delete the top element
    pop(&stackTop);

    return 0;
}
