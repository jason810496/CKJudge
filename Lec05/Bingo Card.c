#include<stdio.h>

int map[260];
int main () {
    int arr[9][9] , ans[64] , cnt = 0;
    int n = 8;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            scanf("%d" , &arr[i][j] );
        }
    }
    for(int i=0,x;i<64;i++){
        scanf("%d" , &x );
        map[ x ] = 1;
    }

    for(int i=1;i<=n;i++){
        int f = 0;
        for(int j=1;j<=n;j++){
            if( map[ arr[i][j] ] ) f++;
        }
        if( f == 8 ) cnt++;
    }

    for(int i=1;i<=n;i++){
        int f = 0;
        for(int j=1;j<=n;j++){
            if( map[ arr[j][i] ] ) f++;
        }
        if( f == 8 ) cnt++;
    }

    int f = 0;
    for(int i=1;i<=8;i++){
        if( map[ arr[i][i] ] ) f++;
    }
    if( f == 8 ) cnt++;

    f=0;
    for(int i=1;i<=8;i++){
        if( map[ arr[n-i+1][i] ] ) f++;
    }
    if( f == 8 ) cnt++;

    printf("%d" , cnt);
    return 0;
}

