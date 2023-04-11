// NOT CONFIRMED BUT ANSWER IS CORRECT
// NEED TO CHECK TIME COMPLEXITY

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, k, n;
    cin >> m >> k >> n;

    int p;
    cin >> p;
    vector<vector<int> > mat1(m, vector<int>(k, 0));
    for (int i = 0; i < p; i++) {
        int row, col, val;
        cin >> row >> col >> val;
        mat1[row - 1][col - 1] = val; 
    }

    int q;
    cin >> q;
    vector<vector<int> > mat2(k, vector<int>(n, 0));
    for (int i = 0; i < q; i++) {
        int row, col, val;
        cin >> row >> col >> val;
        mat2[row - 1][col - 1] = val; 
    }

    vector<vector<int> > mat3(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < k; p++) {
                mat3[i][j] += mat1[i][p] * mat2[p][j];
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat3[i][j] != 0) {
                count++;
            }
        }
    }
    
    cout << count << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat3[i][j] != 0) {
                cout << i+1 << " " << j+1 << " " << mat3[i][j] << endl; 
            }
        }
    }

    return 0;
}
