#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue* q, int element) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", element);
        return;
    }
    q->data[q->rear] = element;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int element = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return element;
}

void printQueue(Queue* q) {
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printQueue(&q); // Output: 1 2 3

    int dequeued = dequeue(&q);
    printf("Dequeued: %d\n", dequeued); // Output: 1
    printQueue(&q); // Output: 2 3

    return 0;
}