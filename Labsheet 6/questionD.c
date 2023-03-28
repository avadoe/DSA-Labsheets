#include <stdio.h>
#include <string.h>

void compute(int arr[], int n){
    int occ[n + 1];
    for(int i = 0; i < n + 1; i++)
        occ[i] = 0;
    
    for(int l = 0, r = 0; l < n; l++){
        occ[arr[l]]++;
        if(occ[arr[r]] == 1)
            printf("%d ", arr[r]);
        else{
            while(!(occ[arr[r]] == 1)){
                r++;
                if(r > l){
                    printf("-1 ");
                    break;
                }
            }
            if(r <= l)
                printf("%d ", arr[r]);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    compute(arr, n);
    return 0;
}