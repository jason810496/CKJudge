#include <stdio.h>

int main(void){
    int n,m;
    scanf("%d%d" , &n , &m);
    
    int A[n];
    int B[m];
    for(int i=0;i<n;i++){
    	scanf("%d" , &A[i] );
    }
    for(int i=0;i<m;i++){
    	scanf("%d" , &B[i] );
    }
    
    int ans[n+m];
    int i=0;
    int j=0;
    int k=0;
    while( i<n && j<m ){
        if( A[i] < B[j]) {
        	ans[k++] = A[i++];
        }
        else{
        	ans[k++] = B[j++];
        }
    }
    
    while( i<n ){
    	ans[k++] = A[i++];
    }
    
    while( j<m ){
    	ans[k++] = B[j++];
    }
    
    for(int i=0;i<n+m;i++){
    	printf("%d " , ans[i] );
    }
    return 0;
}


