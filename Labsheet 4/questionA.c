#include <stdio.h>
#include <stdlib.h>

struct slot{
    int startTime;
    int endTime;
};

typedef struct slot slot;

void merge(slot arr[], int s, int mid, int e){
    int i, j, k;
    int n1 = mid - s + 1;
    int n2 = e - mid;
    slot L[n1], R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[s + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    i = 0; j = 0; k = s;

    while(i < n1 && j < n2){
        if(L[i].startTime <= R[j].startTime){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(slot arr[], int s, int e){
    if(s < e){
        int mid = s + (e - s)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);

        merge(arr, s, mid, e);
    }
}


int main() {
    int n;
    scanf("%d", &n);

    // Read the preferred slots
    slot* slots = (slot*)malloc(n * sizeof(slot));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &slots[i].startTime, &slots[i].endTime);
    }

    // Sort the slots based on the starting time
    mergeSort(slots, 0, n - 1);

    // Merge overlapping slots
    slot* merged_slots = (slot*)malloc(n * sizeof(slot));
    int top = -1;
    for (int i = 0; i < n; i++) {
        if (top == -1 || slots[i].startTime > merged_slots[top].endTime) {
            // No overlap, push the slot
            merged_slots[++top] = slots[i];
        } else {
            // Overlap, merge the slots
            merged_slots[top].endTime = (merged_slots[top].endTime > slots[i].endTime) ? merged_slots[top].endTime : slots[i].endTime;
        }
    }

    // Print the merged slots
    printf("%d\n", top + 1);
    for (int i = 0; i <= top; i++) {
        printf("%d %d\n", merged_slots[i].startTime, merged_slots[i].endTime);
    }

    free(slots);
    free(merged_slots);
    return 0;
}