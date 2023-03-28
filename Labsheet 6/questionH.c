#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularQueue {
    Node* front;
    Node* rear;
    int size;
} CircularQueue;

Node* createNode(int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

CircularQueue* createCq() {
    CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
    cq->front = NULL;
    cq->rear = NULL;
    cq->size = 0;
    return cq;
}

void enqueue(CircularQueue* cq, int val) {
    Node* newNode = createNode(val);
    if (cq->rear == NULL) {
        cq->front = newNode;
    } else {
        cq->rear->next = newNode;
    }
    cq->rear = newNode;
    cq->rear->next = cq->front;
    cq->size++;
}

void dequeue(CircularQueue* cq) {
    if (cq->front == NULL) {
        return;
    }
    int val = cq->front->data;
    if (cq->front == cq->rear) {
        cq->front = NULL;
        cq->rear = NULL;
    } else {
        cq->front = cq->front->next;
        cq->rear->next = cq->front;
    }
    cq->size--;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    CircularQueue* cq = createCq();
    for (int i = 1; i <= n; i++) {
        enqueue(cq, i);
    }
    while (cq->size > 1) {
        for (int i = 1; i < k; i++) {
            cq->rear = cq->front;
            cq->front = cq->front->next;
        }
        dequeue(cq);
    }
    printf("%d\n", cq->front->data);
    return 0;
}
