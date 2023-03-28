#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 14

char ans[MAX_LENGTH][MAX_LENGTH];
int ansSize = 0;

void generateParenthesis(char* s, int n, int open, int close){
    if(open == n/2 && close == n/2){
        strcpy(ans[ansSize], s);
        ansSize++;
        return;
    }
    if(open < n/2){
        char s1[MAX_LENGTH];
        strcpy(s1, s);
        strcat(s1, "(");
        generateParenthesis(s1, n, open + 1, close);
    }
    if(close < open){
        char s2[MAX_LENGTH];
        strcpy(s2, s);
        strcat(s2, ")");
        generateParenthesis(s2, n, open, close + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    generateParenthesis("", n, 0, 0);
    printf("%d\n", ansSize);
    for(int i = 0; i < ansSize; i++){
        printf("%s\n", ans[i]);
    }
    return 0;
}