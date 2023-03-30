#include <iostream>
using namespace std;

string nextPalindrome(string num){
    int n = num.size();
    bool allNines = true;

    for(int i = 0; i < n; i++){
        if(num[i] != '9'){
            allNines = false;
            break;
        }
    }

    if(allNines){
        string ans(n + 1, '0');
        ans[0] = '1';
        ans[n] = '1';

        return ans;
    }

    int mid = n / 2;
    int i = mid - 1;
    int j = (n % 2 == 0) ? mid : mid + 1;

    while(i >= 0 && num[i] == num[j]){
        i--;
        j++;
    }

    bool leftSmaller = false;
    if(i < 0 || num[i] < num[j])
        leftSmaller = true;

    while(i >= 0){
        num[j] = num[i];
        i--;
        j++;
    }

    if(leftSmaller){
        int carry = 1;
        i = mid - 1;

        if(n % 2 == 1){
            int x = num[mid] - '0' + carry;
            carry = x / 10;
            num[mid] = (x % 10) + '0';
            j = mid + 1;
        }
        else{
            j = mid;
        }

        while(i >= 0){
            int x = num[mid] - '0' + carry;
            carry = x / 10;
            num[mid] = (x % 10) + '0';
            num[j] = num[i];
            i--;
            j++;
        }
    }

    return num;
}

int main()
{
    int n;
    cin >> n;

    string num;
    cin >> num;

    string ans = nextPalindrome(num);
    cout << ans << endl;
    return 0;
}