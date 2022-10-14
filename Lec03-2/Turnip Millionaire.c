#include<stdio.h>

float w=0.9 , u=0.1 , b=-51 , u_=-0.98 , b_=153;

float arr[6] ,Hidden[6],ans[6];
float h(int t){
    return w*arr[t-1] +u*Hidden[t-1] + b;
}

float y(int t){
    Hidden[t]=h(t);
	return u_ *Hidden[t] + b_ ;
}
int main () {
    
    Hidden[0]=0;
    scanf("%f" , &arr[0] );
    for(int i=1;i<=5;i++){
        ans[i] = y(i);
        arr[i] = ans[i];
        printf("%.1f " , ans[i] );
    }
    
    return 0;
}