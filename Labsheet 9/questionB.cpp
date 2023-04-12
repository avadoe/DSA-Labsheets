// DONE

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<pair<int, int> > queries(q);

    for(int i = 0; i < q; i++){
        int left, right;
        cin >> left >> right;

        queries[i].first = left;
        queries[i].second = right;
    }

    vector<int> prefix(n, 0);
    int platesSoFar = 0;

    if(s[0] == '*'){
        platesSoFar = 1;
        prefix[0] = platesSoFar;
    }

    for(int i = 1; i < n; i++){
        if(s[i] == '*'){
            platesSoFar++;
        }

        prefix[i] = platesSoFar;
    }   

    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        ans[i] = prefix[queries[i].second] - prefix[queries[i].first];
    }

    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }

    return 0;
}   