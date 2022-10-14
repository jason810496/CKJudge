#include <stdio.h>
#include <stdlib.h>

int arr[7] = {};
int Player =100 , Dragon=100;

int Odd(){
	return ( (arr[1]+arr[2]+arr[3]) % 2 == 1 );
}
int P_Ascending(){
	return ( (arr[6]>arr[5]) && (arr[5]>arr[4]) ) ;
}
int P_Identical(){
	return ( (arr[4]%2) == (arr[5]%2) ) || ( (arr[5]%2) == (arr[6]%2) ) ;
}
int D_Greater(){
	return ( abs(arr[5]-arr[4]) > arr[6] ) ;
}
int D_NotEqual(){
	return ( (arr[4]+arr[5])!=arr[6] ) ;
}

int main () {
    
    while( Player>0 && Dragon>0 ){
    	for(int i=1;i<=6;i++){
            scanf("%d" , &arr[i] );
        }
        
        if( Odd() ){ // Player 
        	if( P_Ascending() ) Dragon-=25;
            else if( P_Identical() ) Dragon-=5 ;
        }
        else{ // Dragon
        	if( D_Greater() ) Player-=15;
            else if( D_NotEqual() ) Player-=5;
        }
    }
    
    if( Player <= 0 ) printf("Dragon wins");
    if( Dragon <= 0 ) printf("Player wins");

    return 0;
}