#include <stdio.h>

double Pow(double x,int n){
    if( n <=0 ) return 1.0;
    if( n&1 ) return x*Pow(x,n-1);
    double t = Pow(x,n/2);
    return t*t;
}
int main(void){
    double r;
    int n;
    scanf("%lf%d" , &r , &n);
    printf("%d" , (int)Pow(r,n) );
    return 0;
}

