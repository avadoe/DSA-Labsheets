#include <stdio.h>
#include <string.h>

int valid_window(char *start,char *end,char *req) {
    char s[end+2-start];
    for (char *l=start;l<=end;l++) {
        s[(int)(l-start)]=*l;
    }
    for (char *l=req;*l!='\0';l++) {
        int f = 0;
        for (int i=0;i<strlen(s);i++) {
            if (*l==s[i]) {
                f=1;
                char s1[100]="";
                strncpy(s1,s,i);
                strcat(s1,s+i+1);
                strcpy(s,s1);
                break;
            }
        }
        if (f==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char sentence[100],word[20];
    scanf("%[^\n]%*c",sentence);
    scanf("%[^\n]%*c",word);
    int sentence_length = strlen(sentence);
    int window_start = 0;
    int window_end = 0;
    int window_length = sentence_length;
    int word_length = strlen(word);

    for (char *i=sentence;i!=sentence+sentence_length-word_length+1;i++) {
        for (char *j=i+word_length-1;j!=sentence+sentence_length;j++) {
            if (valid_window(i,j,word)!=0) {
                if ((int)(j+1-i)<window_length) {
                    window_start = (int)(i-sentence);
                    window_end = (int)(j-sentence);
                    window_length = (int)(j+1-i);
                }
                break;
            }
        }
    }

    if (window_end-window_start == 0) {
        printf("NO WINDOW\n");
    } else {
        printf("%d %d\n",window_start+1,window_end+1);
        for (char *c=(sentence+window_start);c<=(sentence+window_end);c++) {
            printf("%c",*c);
        }
        printf("\n");
    }

    return 0;
}