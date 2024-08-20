#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Define the structure for the doubly linked list
typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a new doubly linked list
DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* dll = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (!dll) {
        printf("Memory error\n");
        return NULL;
    }
    dll->head = NULL;
    dll->tail = NULL;
    return dll;
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(DoublyLinkedList* dll, int data) {
    Node* newNode = createNode(data);
    if (dll->head == NULL) {
        dll->head = newNode;
        dll->tail = newNode;
    } else {
        dll->tail->next = newNode;
        newNode->prev = dll->tail;
        dll->tail = newNode;
    }
}

// Function to print the doubly linked list in forward order
void printForward(DoublyLinkedList* dll) {
    Node* temp = dll->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the doubly linked list in backward order
void printBackward(DoublyLinkedList* dll) {
    Node* temp = dll->tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    DoublyLinkedList* dll = createDoublyLinkedList();
    insertAtEnd(dll, 10);
    insertAtEnd(dll, 20);
    insertAtEnd(dll, 30);
    insertAtEnd(dll, 40);
    insertAtEnd(dll, 50);

    printf("Forward Traversal: ");
    printForward(dll);

    printf("Backward Traversal: ");
    printBackward(dll);

    return 0;
}