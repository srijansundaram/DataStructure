#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_NODES];
    int numNodes;
} Graph;

// Function to create a graph
Graph* createGraph(int nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = nodes;
    for (int i = 0; i < nodes; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjList[i];
        printf("Node %d:", i);
        while (temp) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    
}

// Function to calculate and print degree of each node
void printDegrees(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        int degree = 0;
        Node* temp = graph->adjList[i];
        while (temp) {
            degree++;
            temp = temp->next;
        }
        printf("Degree of node %d: %d\n", i, degree);
    }
}

// Function to find and print key players (high degree nodes)
void findKeyPlayers(Graph* graph, int threshold) {
    printf("Key Players (Degree > %d):\n", threshold);
    for (int i = 0; i < graph->numNodes; i++) {
        int degree = 0;
        Node* temp = graph->adjList[i];
        while (temp) {
            degree++;
            temp = temp->next;
        }
        if (degree > threshold) {
            printf("Node %d (Degree: %d)\n", i, degree);
        }
    }
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

int main() {
    int nodes = 6; // Example: 6 individuals
    Graph* graph = createGraph(nodes);

    // Adding edges (relationships)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 1, 5); // Adding more connections for complexity

    // Print the graph
    printf("Social Network Graph:\n");
    printGraph(graph);
    
    // Print degrees of each node
    printf("\nDegrees of each node:\n");
    printDegrees(graph);
    
    // Find key players (degree greater than 2)
    findKeyPlayers(graph, 2);

    // Free allocated memory
    freeGraph(graph);
    
    return 0;
}