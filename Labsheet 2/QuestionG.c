// COMPLETE

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

struct Node_t {
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *addToList(Node *head, int val) {
    Node *newNode = createNode(val);
    if (head == NULL) {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}

// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList(int n) {
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (head == NULL) {
        head = addToList(head, x);
        } else {
        addToList(head, x);
        }
    }
    return head;
}

void printList(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

void freeList(Node *head) {
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}

Node* removeRepeatedNodes(Node* head){
    if(head == NULL){
        return head;
    }
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = currNode->next;
    while(nextNode){
        if(currNode->data == nextNode->data){
            while(nextNode != NULL && nextNode->data == currNode->data){
                nextNode = nextNode->next;
            }
            if(prevNode == NULL){
                head = nextNode;
            }else{
                prevNode->next = nextNode;
            }
        }else{
            prevNode = currNode;
        }
        currNode = nextNode;
        if(nextNode != NULL){
            nextNode = currNode->next;
        }
    }
    return head;
}

int main() {
    int n;
    Node* head = readList(n);
    printList(head);
    Node* ans = removeRepeatedNodes(head);
    printList(ans);
    return 0;
}