#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node node;

node* createNode(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

node* append(node* head, int val){
    node* newNode = createNode(val);
    if(head == NULL){
        head = newNode;
        return head;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode;
}

node* readList(int n){
    scanf("%d", &n);
    node* head = NULL;
    node* temp = head;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(head == NULL){
            head = append(head, x);
        }else{
            append(head, x);
        }
    }
    return head;
}

void printList(node* head){
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

void freeList(node* head){
    node* curr, *nxt;
    curr = head;
    while(curr){
        nxt = curr->next;
        free(curr);
        curr = nxt;
    }
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

int getMedian(node* head){
    if(head == NULL){
        return -1;
    }
    if(head->next == NULL){
        return head->data;
    }
    node* fast = head;
    node* slow = head;

    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(getLen(head)%2 == 0){
        return (slow->data + slow->next->data)/2;
    }
    return slow->data;
}

node* mergeLists(node* head1, node* head2){
    node* temp1 = head1;
    node* temp2 = head2;

    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    node* ans;
    if(temp1->data < temp2->data){
        ans = createNode(temp1->data);
        ans->next = mergeLists(temp1->next, temp2);
    }
    else{
        ans = createNode(temp2->data);
        ans->next = mergeLists(temp1, temp2->next);
    }
    return ans;
}    

node* sortList(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* fast = head;
    node* slow = head;
    node* prev;

    while(fast && fast->next){
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    prev->next = NULL;
    node* t1 = sortList(head);
    node* t2 = sortList(slow);

    return mergeLists(t1, t2);
}

node* sortLista(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* fast = head;
    node* slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    node* temp = slow->next;
    slow->next = NULL;

    node* t1 = sortList(head);
    node* t2 = sortList(temp);

    return mergeLists(t1, t2);
}

node* reverseList(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* currNode = head;
    node* prevNode = NULL;
    node* nextNode;

    while(currNode != NULL){
        nextNode = currNode->next;
        currNode->next = prevNode;

        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}

bool palindrome(node* head){
    node* fast = head;
    node* slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    node* secondHalf = reverseList(slow->next);
    fast = head;

    while(secondHalf){
        if(secondHalf->data != fast->data){
            return false;
        }
        secondHalf = secondHalf->next;
        fast = fast->next;
    }
    return true;
}

void oddThenEven(node* head){
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while(odd->next && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
}

node* removeRepeatedNodes(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* prevNode = NULL;
    node* currNode = head;
    node* nextNode = currNode->next;

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

node* removeKFromEnd(node* head, int k){
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
    slow->next = slow->next->next;
    return head;
}

int main()
{
    int n1;
    node* head1 = readList(n1);
    printList(head1);
    node* ans = sortLista(head1);
    printList(ans);
    return 0;
}