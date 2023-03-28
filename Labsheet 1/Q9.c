#include <stdio.h>
#include <stdlib.h>

void forward(int* front, int* back){
    int i;
    int temp = *front;
    for(i = 0; i < (int)(back - front); i++){
        front[i] = front[i + 1]; 
    }
    front[i] = temp;
}

void backward(int* front, int* back){
    int i;
    int temp = *back;

    for(i = (int)(back - front); i > 0; i--){
        front[i] = front[i - 1];
    }
    front[i] = temp;
}

int main() {
    int k,n;
    scanf("%d %d",&k, &n);
    int *p =  (int *) malloc(n*sizeof(int));

    for (int *i=p;i<(p+n);i++)
        scanf("%d",i);

    int *mid = NULL;
    for (int *i=p;i<(p+n);i++) {
        if (mid==NULL && *i==(k+1)/2) {
            mid = i;
            break;
        }
    }

    for (int *i=mid; i>=p; i--) {
        if (*i>*mid) {
            forward(i,mid);
            mid--;
        }
    }

    for (int *i=mid; i<(p+n); i++) {
        if (*i<*mid) {
            backward(mid,i);
            mid++;
        }
    }

    for (int *i=p;i<(p+n);i++)
        printf("%d ",*i);
    printf("\n");

    return 0;
}