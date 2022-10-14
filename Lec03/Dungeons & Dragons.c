#include<stdio.h>

const int n = 6;
const int ATK = 10 ;
int main () {
    int arr[n] , sum=0 ;
    for(int i=0;i<n;i++){
    	scanf("%d" , &arr[i] );
    }
    for(int i=0;i<3;i++){
    	sum+=arr[i];
    }
    
    if( sum > ATK ){
    	printf("Dragon attacks: ");
        if( arr[3]==arr[4] || arr[4]==arr[5] || arr[3]==arr[5] ){
        	printf("Miss");
        }
        else if( arr[3]+arr[4] != arr[5] ){
        	printf("Normal Hit");
        }
        else printf("Critical Hit");
    }
    else{
    	printf("Player attacks: ");
        if( arr[3]==arr[4] && arr[4]==arr[5] && arr[3]==arr[5] ){
        	printf("Critical Hit");
        }
        else if( arr[3]+arr[4] >= arr[5] ){
        	printf("Normal Hit");
        }
        else printf("Miss");
    }
    return 0;
}
