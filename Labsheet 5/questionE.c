#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    int cnt = 0;
    for(int l = 0, r = 0; r < n; r++){
        if(arr[r]==0)cnt++;
        while(cnt>k){
            if(arr[l]==0)cnt--;
            l++;
        }
        ans = ans > r-l+1?ans:r-l+1;
    }
    printf("%d",ans);
    return 0;
}