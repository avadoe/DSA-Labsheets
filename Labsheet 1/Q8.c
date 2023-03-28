#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void revWord(char *c){
    int i = 0;
    int len = strlen(c);
    int j ;

    while(i < len){
        j = i;

        while (c[j] != ' ' && c[j] != '\0') {
            j++;
        }
        int k = j - 1;

        while(i < k){
            char temp = c[i];
            c[i] = c[k];
            c[k] = temp;

            i++;
            k--;
        }
        i = j + 1;
    }
}

bool isPalindrome(char *c){
    int st = 0;
    int en = strlen(c) - 1;

    while(st < en){
        if(c[st] != c[en]){
            return false;
        }
        st++;
        en--;
    }
    return true;
}

int main()
{
    char c[1000];
    scanf("%[^\n]s", c);
    revWord(c);
    printf("%s\n", c);

    char* word = strtok(c, " ");
    while(word){
        if(isPalindrome(word)){
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}