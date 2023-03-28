#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void countPrimes(int n, int q, int* queries){
    bool* isPrime = malloc((n + 1) * sizeof(bool));

    for(int i = 2; i <= n; i++){
        isPrime[i] = true;
    }

    for(int i = 2; i*i <= n; i++){
        if(isPrime[i] == true){
            for(int j = i + i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    int* primeCounts = calloc(q, sizeof(int));

    int count = 0;
    for(int i = 0; i <= n; i++){
        if(isPrime[i]){
            count++;
        }
        for(int j = 0; j < q; j++){
            if(i == queries[j]){
                primeCounts[j] = count;
            }
        }
    }

    for(int i = 0; i < q; i++){
        printf("%d ", primeCounts[i]);
    }

    free(isPrime);
    free(primeCounts);
}

void checkPrimes(int n, int q, int* queries) { // Specified time complexity
    bool* isPrime = malloc((n + 1) * sizeof(bool));

    for(int i = 2; i <= n; i++){
        isPrime[i] = true;
    }

    for(int p = 2; p*p <= n; p++) {
        if(isPrime[p]) {
            for(int i = p*p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    int* primeCounts = calloc(q, sizeof(int));

    int count = 0;
    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            count++;
        }
        for(int j = 0; j < q; j++){
            if(i == queries[j]){
                primeCounts[j] = count;
            }
        }
    }

    for(int i = 0; i < q; i++){
        printf("%d ", primeCounts[i]);
    }

    free(isPrime);
    free(primeCounts);
}


int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int* queries = malloc(q * sizeof(int));

    for(int i = 0; i < q; i++){
        scanf("%d", &queries[i]);
    }

    checkPrimes(n, q, queries);
}