#include<stdio.h>

int main () {
    int n=5;
    long double arr[n];
    for(int i=0;i<n;i++){
        scanf("%Lf" , &arr[i] );
    }
    long double result = 1.0;
    for(int i=0;i<n;i++){
    	result *= arr[i];
    }
    printf("%.15Lf" , result );
    return 0;
}
