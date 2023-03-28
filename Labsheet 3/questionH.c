// COMPLETE

#include <stdio.h>

int getSquareRoot(int n){
    int start = 0;
    int end = n;
    int ans;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(mid * mid <= n){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    int ans = getSquareRoot(n);

    printf("%d\n", ans);
    return 0;
}