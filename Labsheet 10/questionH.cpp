// DONE

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> freq;

    vector<int> C;

    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
        freq[A[i]]++;
    }

    vector<int> B(m);
    for(int i = 0; i < m; i++){
        cin >> B[i];
        while(freq[B[i]] > 0){
            C.push_back(B[i]);
            freq[B[i]]--;
        }
    }

    sort(A.begin(), A.end());

    for(int i = 0; i < n; i++){
        if(freq[A[i]] > 0){
            while(freq[A[i]] > 0){
                C.push_back(A[i]);
                freq[A[i]]--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << C[i] << " ";
    }

    cout << endl;

    return 0;
}