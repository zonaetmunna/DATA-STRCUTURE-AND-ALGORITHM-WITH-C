#include <stdio.h>
#define MAX_SIZE 10

// Queue structure
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Function to initialize the queue
void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return queue->size == MAX_SIZE;
}

// Function to enqueue an item
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Insertion failed.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = item;
    queue->size++;
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", queue.data[queue.front]);
    printf("Rear element: %d\n", queue.data[queue.rear]);

    return 0;
}

