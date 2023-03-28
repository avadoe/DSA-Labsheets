#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 1000

int arr[N];
int s, n;
bool used[N];

bool subsetSum(int idx, int sum){
    if(sum == s){
        printf("POSSIBLE\n");   
        for(int i = 0; i < n; i++){
            if(used[i]){
                printf("%d ", i);
            }
        }
        return true;
    }
    if(idx == n){
        return false;
    }
    used[idx] = true;
    if(subsetSum(idx + 1, sum + arr[idx])){
        return true;
    }
    used[idx] = false;
    if(subsetSum(idx + 1, sum)){
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &s);
    if(!subsetSum(0, 0)){
        printf("NOT POSSIBLE\n");
    }
    return 0;
}