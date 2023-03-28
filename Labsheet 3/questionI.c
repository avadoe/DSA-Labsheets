// COMPLETE

#include <stdio.h>

int findStep(int n){
    int left = 0;
    int right = n - 1;

    while(left < right){
        int mid = (left + right)/2;

        int comparisons = n*(n - 1)/2 - (n - mid)*(n - mid - 1)/2;
        if(comparisons < n*(n - 1)/4){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", findStep(n));
    return 0;
}