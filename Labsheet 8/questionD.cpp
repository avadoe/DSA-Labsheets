// WRONG

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n, q;
    cin >> n >> q;

    vector<long long> arr(n, 0);

   long long k, q_type, x, start, end, ans;

   for(int i = 0; i < q; i++){
        cin >> q_type >> k;

        switch (q_type)
        {
        case 1:
            arr[k] = !arr[k];
            break;

        case 2:
            start = k;
            end = arr.size() - 1;
            ans = -1;

            while(start < end){
                long long mid = start + (end - start)/2;

                if(arr[mid]){
                    ans = mid;
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }

            cout << ans << endl;
            break;

        case 3:
            start = 0;
            end = k;
            ans = -1;

            while(start < end){
                long long mid = start + (end - start)/2;

                if(arr[mid]){
                    ans = mid;
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }

            cout << ans << endl;
            break;
    
        default:
            break;
        }
   }

   return 0;
}