#include<stdio.h>
#include<stdlib.h>
#define ll long long 
int main () {
    int n;
    scanf("%d" , &n);
    
    int arr[n];
    
    for(int i=1;i<=n;i++){
    	scanf("%d" , &arr[i] );
    }
    
    ll prefix=0;
    
    for(int i=1;i<=n;i++){
        prefix+=arr[i];

        if( prefix % arr[i] == 0 ){
            printf("%lld %d\n" , prefix , arr[i] );
        }
    }
    
    return 0;
}