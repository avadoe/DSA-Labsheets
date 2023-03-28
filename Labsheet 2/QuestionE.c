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

int getLen(Node* head){
    if(head == NULL){
        return 0;
    }
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* reverseList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

bool palindrome(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* t = reverseList(slow->next);
    fast = head;

    while(t){
        if(t->data != fast->data){
            return false;
        }
        t = t->next;
        fast = fast->next;
    }
    return true;
}

// Function definition goes here
int main() {
    int n;
    Node* head = readList(n);
    printList(head);
    head = reverseList(head);
    printList(head);

    int x = getLen(head);
    printf("Length: %d\n", x);

    bool y = palindrome(head);
    printf("%d\n", y);
    return 0;
}