#include <iostream>
#include <vector>
using namespace std;

double getMedian(int a[], int n, int b[], int m){
    int minIdx = 0, maxIdx = n, i, j, median;

    while(minIdx <= maxIdx){
        i = (minIdx + maxIdx) / 2;
        j = (m + n + 1)/2 - i;

        if(j < 0){
            maxIdx = i - 1;
            continue;
        }

        if(i < n && j > 0 && b[j - 1] > a[i]){
            minIdx = i + 1;
            continue;
        }

        if(i == 0){
            median = b[j - 1];
        }
        else if(j == 0){
            median = a[i - 1];
        }
        else{
            median = max(a[i - 1], b[j - 1]);
        }

        break;
    }

    if((m + n) % 2 == 1){
        return (double)median;
    }

    if(i == n){
        return (median + b[j])/2.0;
    }

    if(j == m){
        return (median+a[i])/2.0;
    }

    return (median + min(a[i], b[j])) / 2.0;
}

int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    double ans = getMedian(a, n, b, m);
    cout << ans << endl;
}