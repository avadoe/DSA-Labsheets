// DONE

#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;

    int arr[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int v;
    cin >> v;

    int x = m - 1, y = 0;

    while(arr[x][y] != v && x < m && y < n){
        if(arr[x][y] > v){
            x--;
        }
        else{
            y++;
        }
    }

    if(x >= m || y >= n){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}