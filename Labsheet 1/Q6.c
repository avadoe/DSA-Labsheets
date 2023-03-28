#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int x){
    if(x < 2){
        return false;
    }
    if(x == 4){
        return false;
    }
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int arr[10] = {0};
    for(int i = x; i <= y; i++){
        if(isPrime(i)){
            int j = i;
            while(j != 0){
                int dig = j % 10;
                j /= 10;
                arr[dig] += 1;
            }
        }
    }

    int max = 0;
    int occ;
    for(int i = 0; i < 10; i++){
        if(arr[i] > max){
            max = arr[i];
            occ = i;
        }
    }

    printf("%d %d\n", occ, max);
}