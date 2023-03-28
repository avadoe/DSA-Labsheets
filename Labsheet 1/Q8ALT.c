#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isPalindrome(char* c){
    int start = 0, end = strlen(c) - 1;

    while(start < end){
        if(c[start] != c[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void revWord(char input[], int i, int j){
    while(i < j){
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    int i, j, k;
    char input[1000];
    
    scanf("%[^\n]%*c", input);  
    i = j = k = 0;

    while(input[i] != '\0'){
        while(input[j + 1] != ' ' && input[j + 1] != '\0'){
            j++;
            k++;
        }
        revWord(input, i, j);
        k += 2;
        i = k;
        j = k;
    }

    int x=0;
    while(input[x] != '\0'){
        printf("%c", input[x]);
        x++;
    }
    printf("\n");
    char* word = strtok(input, " ");
    while(word){
        if(isPalindrome(word) && strlen(word) != 1){
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    return 0;
}