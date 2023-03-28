#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
int main(){
    int n,k;
    scanf("%d",&k);
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
 for(int j=0;j<n-1;j++){
    for(int i=0;i<n-j-1;i++){
        if(a[i]>=(k+1)/2 && a[i+1]<=(k+1)/2){
          swap(&a[i],&a[i+1]);
        }

    }
}
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 1;
}