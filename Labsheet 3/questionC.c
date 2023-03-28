// COMPLETE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Try for a better twoSum algorithm, since the linked list is sorted

bool checkSum(node* head, int target){
    node* end = head;
    while(end->next){
        end = end->next;
    }
    node* start = head;
    node* second = head->next;
    while(start){
        while(second){
            if(start->data + second->data == target){
                return true;
            }
            second = second->next;
        }
        start = start->next;
    }
    return false;
}

int main()
{
    int n, k;
    scanf("%d %d", &k, &n);
    node* head = makeList(n);
    forwardTraversal(head);
    backwardTraversal(head);

    bool ans = checkSum(head, k);
    printf("%d", ans);

    return 0;
}