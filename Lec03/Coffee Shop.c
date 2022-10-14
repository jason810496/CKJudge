#include <stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int main() {
	int arr[5] = { 0 , AMERICANO , LATTE , CAPPUCCINO , MOCHA } ;
    int ans  = 0  , opt , cup ;
    scanf("%d%d" , &opt , &cup );
    if( opt < 1 || opt > 5 ) printf( "Wait, what?");
    else{
        ans = arr[opt] * cup;
   		printf("The total price is %d dollars!" , ans );
    }
    return 0;
}