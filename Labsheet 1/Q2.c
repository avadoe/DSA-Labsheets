#include <stdio.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    int p,q;
    scanf("%d %d",&p,&q);
    int b[p][q];
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<m-p+1;i++){
        for(int j=0;j<n-q+1;j++){
            int flag=1;
            if(a[i][j] == b[0][0]){
                for(int k=0;k<p;k++){
                    for(int l=0;l<q;l++){
                        if(a[i+k][j+l]!=b[k][l]){
                            flag=0;
                        }
                    }
                }
                if(flag){
                    printf("YES");
                    return 0;
                }
            }
        }
    }

    for(int i=0;i<m-p+1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<p;k++){
                int flag=1;
                if(a[i][j] == b[k][0]){
                    for(int l=0;l<q;l++){
                        if(a[i][j+l]!=b[k][l]){
                            flag=0;
                        }
                }
                if(flag){
                    printf("PARTIAL");
                    return 0;
                }
            }
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n-q+1;j++){
            for(int k=0;k<q;k++){
                int flag=1;
                if(a[i][j] == b[0][k]){
                    for(int l=0;l<p;l++){
                        if(a[i+1][j]!=b[l][k]){
                            flag=0;
                        }
                }
                if(flag){
                    printf("PARTIAL");
                    return 0;
                }
            }
            }
        }
    }

    printf("NO");
    return 0;
}