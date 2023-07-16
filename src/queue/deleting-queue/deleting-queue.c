
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

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->size == 0;
}

// Function to dequeue an item
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Deletion failed.\n");
        return;
    }

    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    dequeue(&queue);
    dequeue(&queue);

    printf("Front element: %d\n", queue.data[queue.front]);
    printf("Rear element: %d\n", queue.data[queue.rear]);

    return 0;
}
