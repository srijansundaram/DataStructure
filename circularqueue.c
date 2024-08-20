#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the size of the queue

typedef struct {
    int front, rear;
    int items[SIZE];
} CircularQueue;

// Function to initialize the circular queue
void initQueue(CircularQueue *q) {
    q->front = q->rear = 0;
}

// Function to check if the queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == q->rear;
}

// Function to add an element to the queue
void enqueue(CircularQueue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->items[q->rear] = element;
    q->rear = (q->rear + 1) % SIZE;
    printf("%d enqueued to the queue\n", element);
}

// Function to remove an element from the queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Return -1 to indicate the queue is empty
    }
    int element = q->items[q->front];
    q->front = (q->front + 1) % SIZE;
    return element;
}

// Function to peek at the front element of the queue
int peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Return -1 to indicate the queue is empty
    }
    return q->items[q->front];
}

// Function to display the elements of the queue
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    displayQueue(&q); // Output: 10 20 30 40 50

    printf("%d dequeued from the queue\n", dequeue(&q)); // Output: 10 dequeued from the queue
    printf("Front element is %d\n", peek(&q)); // Output: 20

    enqueue(&q, 60);
    displayQueue(&q); // Output: 20 30 40 50 60

    return 0;
}
