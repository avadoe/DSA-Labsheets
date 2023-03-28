// COMPLETE

#include <stdio.h>
#include <stdlib.h>

struct BITS{
    char email[39];
    char id[13];
    char branchName[5];
}typedef bits;

// BRANCH NAME CAN BE ONE OF CS, ECE or EEE

int main()
{
    bits b;
    scanf("%s", b.email);
    scanf("%s", b.branchName);

    for(int i = 0; i < 4; i++){
        b.id[i] = b.email[i + 1];
    }
    b.id[4] = 'A';
    if(b.branchName[0] == 'C' && b.branchName[1] == 'S'){
        b.id[5] = '7';
    }
    else if(b.branchName[0] == 'E' && b.branchName[1] == 'C' && b.branchName[0] == 'E'){
        b.id[5] = 'A';
    }
    else if(b.branchName[1] == 'E'){
        b.id[5] = '3';
    }
    else{
        return 0;
    }
    b.id[6] = 'P';
    b.id[7] = 'S';
    for(int i = 8; i < 12; i++){
        b.id[i] = b.email[i - 3];
    }
    b.id[12] = 'H';

    for(int i = 0; i < 13; i++){
        printf("%c", b.id[i]);
    }
}