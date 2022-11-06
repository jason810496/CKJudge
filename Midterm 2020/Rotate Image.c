#include <stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(void){
    int R;
    int n,m;
    scanf("%d%d%d" ,&R, &n,&m);
    int arr[n][m],arr2[m][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d" , &arr[i][j] );
        }
    }

    
    
    switch( R ){
        case 0 : {
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%d " , arr[i][j] );
                }
                printf("\n");
            }

            break;
        }
        case 90: {

            for(int j=0;j<m;j++){
                for(int i=0;i<n;i++){
                    printf("%d " , arr[n-i-1][j] );
                }
                printf("\n");
            }

            break;
        }
        case 180 : {
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%d " , arr[n-i-1][m-j-1] );
                }
                printf("\n");
            }

            break;
        }
        case 270 : {
            for(int j=0;j<m;j++){
                for(int i=0;i<n;i++){
                    printf("%d " , arr[i][m-j-1] );
                }
                printf("\n");
            }
            break;
        }
    }
    
    return 0;
}

