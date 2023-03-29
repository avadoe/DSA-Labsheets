#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> number(n);

    string A;
    cin >> A;

    for(int i = 0; i < n; i++){
        char c = A[i];

        number[i] = c - '0';
    }

    int left, right;

    if(n % 2 == 0){
        left = n / 2 - 1;
        right = n / 2;
    }else{
        left = n / 2;
        right = n / 2;
    }

    while(left >= 0 && number[left] == number[right]){
        left--;
        right++;
    }

    if(left > 0 && number[left] > number[right]){
        bool isEven = (n % 2 == 0);
        int carry = 1;

        number[left] += carry;
    }
}