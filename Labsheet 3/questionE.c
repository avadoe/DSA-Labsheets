// COMPLETE

// (n - k)th node should point to null

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* createNode(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

node* insertAtEnd(node *head, int val){
    node* newNode = malloc(sizeof(node));
    if(head == NULL){
        return newNode;
    }
    node* temp = head;
    temp->data = val;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return newNode;
}

node* makeList(int n){
    node* head = NULL;

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(head == NULL){
            head = createNode(x);
        }else{
            node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = createNode(x);
            temp->next->prev = temp;
        }
    }
    return head;
}

void forwardTraversal(node* head){
    if(head == NULL){
        return;
    }
    node* temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void backwardTraversal(node* head){
    if(head == NULL){
        return;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int getLen(node* head){
    if(head == NULL){
        return 0;
    }
    node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

node* rotate(node* head, int k){
    if(getLen(head) < k){
        printf("NOT POSSIBLE");
        exit(1);
    }
    node* fast = head;
    node* slow = head;

    while(k){
        fast = fast->next;
        k--;
    }
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    node* temp = slow->next;
    slow->next = NULL;

    node* trav = temp;
    while(trav->next){
        trav = trav->next;
    }
    trav->next = head;
    head->prev = trav;

    return temp;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    node* head = makeList(n);
    // forwardTraversal(head);
    // backwardTraversal(head);

    node* ans = rotate(head, k);
    forwardTraversal(ans);
    return 0;
}