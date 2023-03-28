#include <stdio.h>
#include <math.h>

int C(int n, int r){
    return tgamma(n + 1)/(tgamma(r + 1) * tgamma(n - r + 1));
}

int getMin(int n, int m)
{
    int kingsPerBanquet = n / m;
    int extraKings = n % m;

    // n%m banquets will have (n/m)+1 kings, and (m - (n%m)) banquets will have (n/m) kings

    int a1 = (n % m) * C((n/m) + 1, 2);
    int a2 = (m - (n % m)) * C((n/m), 2);

    return a1 + a2;
}

int getMax(int n, int m)
{
    // (m - 1) banquets will have 1 king each, and the remaining banquet will have (n - m + 1) 
    // kings

    int ans = C(n - m + 1, 2);
    return ans;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d %d\n", getMin(n, m), getMax(n, m));
}