#include<stdio.h>

int main () {
    int mx=-1 , mn = 2147483647 ,x ;
    
    scanf("%d" , &x );
    
    while( x!=-1 ){
        mx = ( mx < x ? x:mx );
        mn = ( mn > x ? x:mn );
    	scanf("%d" , &x );
    }
    
    printf("%d" , mx-mn);
    
    return 0;
}