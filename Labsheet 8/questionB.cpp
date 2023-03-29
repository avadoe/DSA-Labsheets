#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    string A;
    cin >> A;

    vector<int> number(n);

    for(int i = 0; i < A.size(); i++)
        number[i] = A[i] - '0';   

    for(int i = 0; i < number.size(); i++)
        cout << number[i] ;

    cout << endl;
}