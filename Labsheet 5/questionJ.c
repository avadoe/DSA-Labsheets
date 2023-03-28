#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int res = 0;
    int count = 0;
    int n, x;

    srand(time(NULL));

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        count++;

        if(rand()%count == 0){
            res = x;
        }
        printf("%d\n", res);
    }
    return 0;
}
