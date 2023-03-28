#include <stdio.h>  
#include <string.h>
#include <stdbool.h>

bool equalArray(int arr1[], int arr2[]){
    for(int i = 0; i < 26; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

int main() {  
    char s1[1000], s2[1000];

    scanf("%s", s1);
    scanf("%s", s2);

    // printf("%s\n", s1);
    // printf("%s\n", s2);

    int arr1[26] = {0};
    int arr2[26] = {0};

    // printf("%d", s1[0] - 'a');

    for(int i = 0; i < strlen(s1); i++){
        char c = s1[i];

        arr1[c - 'a'] += 1;
    }   
    for(int i = 0; i < strlen(s2); i++){
        char c = s2[i];

        arr2[c - 'a'] += 1;
    }   

    if(!equalArray(arr1, arr2)){
        printf("NOT POSSIBLE\n");
        return 0;
    }
    if(equalArray(arr1, arr2)){
        printf("POSSIBLE\n");

        for(int i = 0; i < strlen(s2); i++){
            for(int j = 0; j < strlen(s1); j++){
                if(s2[i] == s1[j]){
                    printf("%d ", j + 1);
                }
            }
        }
        printf("\n");
    }
    return 0;
}  