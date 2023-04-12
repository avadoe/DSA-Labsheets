// DONE

#include <iostream>
#include <vector>
using namespace std;

int maxCocaColaBottles(vector<int>& happinessChanges) {
    int n = happinessChanges.size();
    vector<long long> prefixSum(n+1);

    for(int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + happinessChanges[i-1];
    }

    int maxBottles = 0;
    long long minPrefixSum = 0;

    for(int i = 1; i <= n; i++) {
        if(prefixSum[i] - minPrefixSum >= 0) {
            maxBottles = i;
        } else {
            minPrefixSum = min(minPrefixSum, prefixSum[i]);
        }
    }

    return maxBottles;
}

int main() {
    int n;
    cin >> n;
    vector<int> happinessChanges(n);

    for(int i = 0; i < n; i++) {
        cin >> happinessChanges[i];
    }

    int maxBottles = maxCocaColaBottles(happinessChanges);

    cout << maxBottles << endl;    
    return 0;
}
