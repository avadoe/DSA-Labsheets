#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; 
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct deque{
    Node* head;
    Node* tail;
    int size;
}deque;

Node* createNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

deque* createDeque(){
    deque* newDeque = (deque*)malloc(sizeof(deque));
    newDeque->head = NULL;
    newDeque->tail = NULL;
    newDeque->size = 0;

    return newDeque;
}

void push_front(deque* dq, int val){
    Node* newNode = createNode(val);
    if(!dq->head){
        dq->head = newNode;
        dq->tail = newNode;   
    }
    else{
        newNode->next = dq->head;
        dq->head->prev = newNode;
        dq->head = newNode;
    }

    dq->size++;
}

void push_back(deque* dq, int val){
    Node* newNode = createNode(val);
    if(!dq->head){
        dq->head = newNode;
        dq->tail = newNode;
    }else{
        newNode->prev = dq->tail;
        dq->tail->next = newNode;
        dq->tail = newNode;
    }
    dq->size++;
}

int pop_front(deque* dq){
    int val = dq->head->data;
    Node* temp = dq->head;
    dq->head = dq->head->next;

    if(!dq->head){
        dq->tail = NULL;
    }else{
        dq->head->prev = NULL;
    }

    dq->size--;
    return val;
}

int pop_back(deque* dq){
    int val = dq->tail->data;
    Node* temp = dq->tail;
    dq->tail = dq->tail->prev;

    if(!dq->tail){
        dq->head = NULL;
    }else{
        dq->tail->next = NULL;
    }

    dq->size--;
    return val;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    deque* dq = createDeque();
    push_back(dq, arr[0]);

    for(int i = 1; i < n; i++){
        if(arr[i] < dq->head->data){
            push_front(dq, arr[i]);
        }else{
            push_back(dq, arr[i]);
        }
    }

    while(dq->size > 0){
        printf("%d ", pop_front(dq));
    }

    free(arr);
    free(dq);

    return 0;
}