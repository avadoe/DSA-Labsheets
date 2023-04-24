#include <iostream>
#include <vector>
using namespace std;

int getMedian(vector<int>& A, vector<int>& B){
    int n = A.size(), m = B.size();
    if(n > m){
        return getMedian(B, A);
    }

    int iMin = 0, iMax = n;
    while(iMax <= iMax){
        int i = (iMax + iMin) / 2;
        int j = (n + m + 1) / 2 - i;

        
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int m;
    cin >> m;
    vector<int> B(m);
    for(int i = 0; i < m; i++){
        cin >> B[i];
    }


}