#include <iostream>
using namespace std;
int main()
{
    int m, k, n;
    cin >> m >> k >> n;

    int p;
    cin >> p;
    int m1[m][k];
    int m2[k][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            m1[i][j] = 0;
        }
    }

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            m2[i][j] = 0;
        }
    }

    for(int i = 0; i < p; i++){
        int row, col, val;

        cin >> row >> col >> val;

        m1[row - 1][col - 1] = val;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int row, col, val;

        cin >> row >> col >> val;

        m2[row - 1][col - 1] = val;
    }

    int m3[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            m3[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int x = 0; x < k; x++){
                m3[i][j] += m1[i][x] * m2[x][j];
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (m3[i][j] != 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (m3[i][j] != 0) {
                cout << i+1 << " " << j+1 << " " << m3[i][j] << endl; 
            }
        }
    }
    return 0;
}