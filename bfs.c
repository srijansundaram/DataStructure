#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
};

// Queue structure for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Add an item to the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Remove an item from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1; // Reset the queue
        }
        return item;
    }
}

// BFS algorithm
void BFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};

    struct Queue* queue = createQueue();
    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("BFS starting from vertex 0:\n");
    BFS(graph, 0);

    // Free allocated memory (not shown here for brevity)

    return 0;
}
