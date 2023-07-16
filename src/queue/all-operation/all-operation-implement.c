
#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDERS 5

typedef struct {
    int orderNumber;
    char itemName[50];
} Order;

typedef struct {
    Order data[MAX_ORDERS];
    int front;
    int rear;
    int size;
} OrderQueue;

void initQueue(OrderQueue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isFull(OrderQueue* queue) {
    return queue->size == MAX_ORDERS;
}

int isEmpty(OrderQueue* queue) {
    return queue->size == 0;
}

void enqueue(OrderQueue* queue, Order order) {
    if (isFull(queue)) {
        printf("Queue is full. Order enqueue failed.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_ORDERS;
    queue->data[queue->rear] = order;
    queue->size++;
    printf("Order %d (%s) has been added to the queue.\n", order.orderNumber, order.itemName);
}

void dequeue(OrderQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Order dequeue failed.\n");
        return;
    }

    Order removedOrder = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_ORDERS;
    queue->size--;
    printf("Order %d (%s) has been dequeued.\n", removedOrder.orderNumber, removedOrder.itemName);
}

void displayFront(OrderQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front order.\n");
        return;
    }

    Order frontOrder = queue->data[queue->front];
    printf("Front Order: %d (%s)\n", frontOrder.orderNumber, frontOrder.itemName);
}

void displayQueue(OrderQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int current = queue->front;
    printf("Order Queue: ");
    while (current != queue->rear) {
        Order currentOrder = queue->data[current];
        printf("%d (%s) -> ", currentOrder.orderNumber, currentOrder.itemName);
        current = (current + 1) % MAX_ORDERS;
    }
    Order rearOrder = queue->data[current];
    printf("%d (%s)\n", rearOrder.orderNumber, rearOrder.itemName);
}

int main() {
    OrderQueue orderQueue;
    initQueue(&orderQueue);

    // Enqueue some orders
    Order order1 = { 1, "Burger" };
    enqueue(&orderQueue, order1);

    Order order2 = { 2, "Pizza" };
    enqueue(&orderQueue, order2);

    Order order3 = { 3, "Fries" };
    enqueue(&orderQueue, order3);

    // Display the front order
    displayFront(&orderQueue);

    // Dequeue an order
    dequeue(&orderQueue);

    // Display the updated queue
    displayQueue(&orderQueue);

    return 0;
}
