// COMPLETE

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
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

node* append(node* head, int val){
    node* newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }
    node* temp = head;
    while(temp->next){
        temp =temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return newNode;
}

node* getTail(node* head){
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    return temp;
}

node* makeList(int n){
    node* head = NULL;

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(!head){
            head = createNode(x);
        }else{
            append(head, x);
        }
    }
    return head;
}

void forwardPrint(node* head){
    if(head == NULL){
        return;
    }
    node* temp = head;
    while(temp){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void backPrint(node* head){
    node* temp = head;
    if(!head){
        return;
    }
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

int getSum(node* a, node* b){
    node* temp = a;
    int sum = 0;
    while(temp != b){
        sum += temp->data;
        temp = temp->next;
    }
    sum += b->data;
    return sum;
}

int* getTeamSizes(node* head){
    node* tail = getTail(head);

    node* startTemp = head;
    node* endTemp = tail;

    int aCount = 1;
    int bCount = 1;
    int aStrength = 0;
    int bStrength = 0;

    int maxStrength = 0;
    int n = getLen(head);
    
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = aCount;
    ans[1] = bCount;

    while(startTemp != tail){
        aStrength = getSum(head, startTemp);
        while(endTemp != startTemp){
            bStrength = getSum(endTemp, tail);
            if(bStrength == aStrength && bStrength > maxStrength){
                maxStrength = bStrength;
                ans[0] = aCount;
                ans[1] = bCount;
            }
            endTemp = endTemp->prev;
            bCount++;
        }
        startTemp = startTemp->next;
        endTemp = tail;
        bCount = 1;
        aCount++;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    node* head = makeList(n);
    forwardPrint(head);
    backPrint(head);
    int* ans = getTeamSizes(head);
    for(int i = 0; i < 2; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}