#include <stdio.h>
#include <stdlib.h>

struct pair{
    int first;
    int second;
};

typedef struct pair pair;

int* getCandidates(int arr[], int n, int k){
    int* ans = malloc(sizeof(int) * k);

    int* voteCount = calloc(n + 1, sizeof(int));
    for(int i = 0; i < n; i++){
        voteCount[arr[i]]++;
    }

    pair* p = malloc(sizeof(pair) * (n + 1));
    for(int i = 0; i <= n; i++){
        p[i].first = voteCount[i];
        p[i].second = i;
    }

    // for(int i = 0; i <= n; i++){
    //     printf("%d ", p[i].first);
    // }
    // printf("\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(p[j].first < p[j + 1].first){
                pair temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < k; i++){
        ans[i] = p[i].second;
    }

    return ans;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int* ans = getCandidates(arr, n, k);
    for(int i = 0; i < k; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}