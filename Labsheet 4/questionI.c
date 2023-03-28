#include <stdio.h>

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int maxGCD(int arr[], int n){
    int i, j, max_gcd = 0;

    for(int i = 0; i < n; i++){
        int newArr[n - 1];

        for(int j = 0; j < i; j++){
            newArr[j] = arr[j];
        }
        for(int j = i + 1; j < n; j++){
            newArr[j - 1] = arr[j];
        }

        int new_gcd = newArr[0];
        for(int j = 0; j < n - 1; j++){
            new_gcd = gcd(new_gcd, newArr[j]);
        }
        if(new_gcd > max_gcd){
            max_gcd = new_gcd;
        }
    }

    return max_gcd;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int ans = maxGCD(arr, n);
    printf("%d\n", ans);
    return 0;
}