// COMPLETE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node_t {
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;

// Creates a new node with given value and returns a pointer to it
Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
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

// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head) {
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}

int getLen(Node* head){
    if(head == NULL){
        return 0;
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* mergeList(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }
    Node* ans;
    if(head1->data < head2->data){
        ans = createNode(head1->data);
        ans->next = mergeList(head1->next, head2);
    }else{
        ans = createNode(head2->data);
        ans->next = mergeList(head1, head2->next);
    }

    return ans;
}

// Function definition goes here
int main() {
    int n1, n2;
    // Function calls go here
    // printf("ENTER HEAD1: ");
    Node* head1 = readList(n1);
    // printf("ENTER HEAD2: ");
    Node* head2 = readList(n2);
    // printList(head1);
    // printList(head2);

    Node* merged = mergeList(head1, head2);
    printList(merged);
    return 0;
}