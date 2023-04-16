// WRONG

#include <iostream>
#include <vector>
using namespace std;

bool checkFortarget(vector<int>& arr1, vector<int>& arr2, int target){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int n = arr1.size(), m = arr2.size();

    int i = 0, j = 0;

    while(j < m && i < n){
        if(arr1[i] - arr2[j] == target){
            return true;
        }

        else if(arr1[i] - arr2[j] < target){
            i++;
        }else{
            j++;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    int happiness1 = 0, happiness2 = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        happiness1 += a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
        happiness2 += b[i];
    }

    if(happiness1 == happiness2){
        cout << "YES\n";
        return 0;
    }

    int diff = happiness1 - happiness2;

    if(diff % 2 != 0){
        cout << "NO\n";
        return 0;
    }

    int personToGive;
    if(diff > 0){
        personToGive = 1;
    }else{
        personToGive = 2;
    }

    int target = diff / 2;

    int left = 0, right = 0;
    int sum = 0;

    if(personToGive == 1){
        if(checkFortarget(a, b, target)){
            cout << "YES\n";
            return 0;
        }else{
            cout << "NO\n";
            return 0;
        }
    }
    else if(personToGive == 2){
        if(checkFortarget(b, a, target)){
            cout << "YES\n";
            return 0;
        }else{
            cout << "NO\n";
            return 0;
        }
    }
}