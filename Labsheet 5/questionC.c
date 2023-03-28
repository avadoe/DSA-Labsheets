#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    char s[n + 1];
    scanf("%s", s);

    int ans = 0;
    int freq[k + 1];

    int count = 0;
    int l = 0;

    for(int i = 0; i < k + 1; i++){
        freq[i] = 0;
    }

    for(int r = 0; r < n; r++){
        freq[s[r] - 'a']++;

        if(freq[s[r] - 'a'] == 1)
            count++;
        
        while(count == k && l <= r){
            ans += n - r;
            freq[s[l] - 'a']--;

            if(freq[s[l] - 'a'] == 0)
                count--;
            l++;
        }
    }

    printf("%d\n", ans);
    return 0;
}