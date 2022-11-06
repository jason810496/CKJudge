#include <stdio.h>

int arr[55][55];

int n, total ;

int main(void){
    
    scanf("%d" , &n );
    total = n*n;
    
    int r=0;
    int c=n/2;
    int cur=1;
    

    while( cur <= total ){
        arr[r][c] = cur++;
        int i = (r-1<0?n-1:r-1);
        int j = (c+1>=n?0:c+1);

        if( arr[i][j] ){
            r++;
            if( r==n ) r=0;
        }
        else{
            r--;
            if( r<0 ) r=n-1;
            c++;
            if( c==n ) c=0;
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d " , arr[i][j] );
        }
        printf("\n");
    }
    return 0;
}

