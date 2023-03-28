// COMPLETE

#include <stdio.h>
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

Node* mergeList(Node* n1, Node* n2){
    Node* temp1 = n1;
    Node* temp2 = n2;

    if(!n1){
        return n2;
    }
    if(!n2){
        return n1;
    }
    Node* ans;
    if(n1->data < n2->data){
        ans = createNode(n1->data);
        ans->next = mergeList(n1->next, n2);
    }else{
        ans = createNode(n2->data);
        ans->next = mergeList(n1, n2->next);
    }
    return ans;
}

Node* sortList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* fast = head;
    Node* slow = head;
    Node* prev;

    while(fast && fast->next){
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    prev->next = NULL;
    Node* l1 = sortList(head);
    Node* l2 = sortList(slow);

    return mergeList(l1, l2);
}

// Function definition goes here
int main() {
    int n;
    Node* head = readList(n);
    printList(head);
    Node* sortedList = sortList(head);
    printList(sortedList);
    return 0;
}