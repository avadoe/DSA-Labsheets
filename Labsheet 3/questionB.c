// COMPLETE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Song{
    int data;
    struct Song* prev;
    struct Song* next;
};
typedef struct Song song;

song* createSong(int val){
    song* newSong = (song*)malloc(sizeof(song));
    newSong->data = val;
    newSong->next = NULL;
    newSong->prev = NULL;

    return newSong;
}

song* addSong(song* head, int val){
    song* newSong = createSong(val);
    if(head == NULL){
        head = newSong;
        return newSong;
    }
    song* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newSong;
    newSong->prev = temp;
    return head;
}

song* currSong(song* s){
    return s;
}

song* playPrev(song* current){
    if(current->prev != NULL){
        return current->prev;
    }
    return current;
}

song* playNext(song* current){
    if(current->next != NULL){
        return current->next;
    }
    return current;
}

void forwardPrint(song* head){
    if(head == NULL){
        return;
    }
    song* temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void backPrint(song* head){
    if(!head){
        return;
    }
    song* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    song* s = NULL;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        s = addSong(s, x);
    }
    int arr[1000] = {0};
    int i = 0;
    while(true){
        int x;
        scanf("%d", &x);
        int y;
        switch (x)
        {
        case 1:
            scanf("%d", &y);
            addSong(s, y);
            break;
        
        case 2:
            s = currSong(s);
            arr[i] = s->data;
            i++;
            break;

        case 3:
            s = playNext(s);
            break;

        case 4:
            s = playPrev(s);
            break;

        case 5:
            i = 0;
            while(arr[i] != 0){
                printf("%d\n", arr[i]);
                i++;
            }
            exit(1);

        case 6:
            scanf("%d", &y);
            s = currSong(s);
            song* nxt = playNext(s);
            song* six = createSong(y);
            s->next = six;
            six->prev = s;
            six->next = nxt;
            nxt->prev = six;
        
        default:
            break;
        }
    }
    return 0;
}