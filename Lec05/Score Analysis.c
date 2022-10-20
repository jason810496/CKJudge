#include<stdio.h>
int score[105] = {};

int main () {

    int n,q;
    scanf("%d" , &n );
    
    for(int i=0,x;i<n;i++){
    	scanf("%d" , &x);
        score[x]++;
    }
    scanf("%d" , &q);
    int l , r;
    while( q--){
    	scanf("%d%d" , &l ,&r );
        int cnt = 0 , idx=0;
        for(int i=0;i<l;i++) cnt+=score[i];
        printf("%d " , cnt);
        cnt = 0;
        for(int i=l;i<r;i++) cnt+=score[i];
        printf("%d " , cnt);
        cnt = 0;
        for(int i=r;i<=100;i++) cnt+=score[i];
        printf("%d\n" , cnt);
        cnt = 0;
    }
    return 0;
}

