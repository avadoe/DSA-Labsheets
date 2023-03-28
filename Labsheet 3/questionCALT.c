#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node node;

node* createNode(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

node* append(node* head, int x){
    node* newNode = createNode(x);
    node* temp = head;
    if(!head){
        head = newNode;
        return newNode;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return newNode;
}

void forwardPrint(node* head){
    if(!head){
        return;
    }
    node* temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void backwardPrint(node* head){
    if(!head){
        return;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

bool checkSum(node* head, int target){
    node* start = head;
    node* end = head;
    while(end->next){
        end = end->next;
    }
    while(start != end){
        int sum = start->data + end->data;
        if(sum == target){
            return true;
        }
        else if(sum > target){
            end = end->prev;
        }
        else{
            start = start->next;
        }
    }
    return false;
}

int main()
{
    int target, n, x;
    node* head = NULL;
    scanf("%d %d", &target, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        head = append(head, x);
    }
    while(head->prev){
        head = head->prev;
    }

    if(checkSum(head, target)){
        printf("1\n");
    }else{
        printf("0\n");
    }
    return 0;
}