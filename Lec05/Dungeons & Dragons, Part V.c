#include <stdio.h>

int main () {
    int n=75 , ans[7] = {};
    int d1 , d2;
    for(int i=0;i<75;i++){
        scanf("%d%d" , &d1 , &d2 );
        if( d2&1 ){
            ans[d1]++;
            if( ans[d1] > 9) ans[d1] = 0;
        }
        else{
            ans[d1]--;
            if( ans[d1] < 0) ans[d1] = 9;
        }
    }
    for(int i=1;i<=6;i++){
        printf("%d " , ans[i] );
    }
    return 0;
}

