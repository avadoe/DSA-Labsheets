#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n ;
    for(n = 1; n <= 1024; n++){
        vector<int> v;
        for(int i = 1; i <= n; i++){
            v.push_back(i);
        }

        int ans;
        while(1){
            int count = 0;
            for(int i = 0; i < v.size(); i++){
                if(v[i]){
                    ans = v[i];
                    count++;
                }
            }

            if(count == 1){
                printf("%d %d\n", n, ans);
                // return 0;
                break;
            }
            count = 0;
            for(int i = 0; i < v.size(); i++){
                if(v[i]==0) continue;

                if(count % 2 == 0){
                    v[i] = 0;
                }
                count++;
            }
            count = 0;
            for(int i = 0; i < v.size(); i++){
                if(v[i]){
                    ans = v[i];
                    count++;
                }
            }
            if(count == 1){
                printf("%d %d\n", n, ans);
                // return 0;
                break;
            }
            count = 0;
            for(int i = v.size() - 1; i >= 0; i--){
                if(v[i] == 0) continue;

                if(count % 2 == 0){
                    v[i] = 0;
                }
                count++;
            }
        }
    }
    return 0;
}