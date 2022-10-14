#include<stdio.h>

void check(unsigned int x){
    int arr[32];
    for(int i=0;i<32;i++){
        arr[i] = x&1;
        x>>=1;
    }    
    for(int i=0;i<32;i++){
        printf("%d " ,arr[31-i] );
    }
    printf("\n");
}
int main(){
    unsigned int ip = 0;
    for(int i=0;i<8;i++){
        char c;
        scanf("%c" , &c );
        ip <<=4;
        if( '0'<= c && c<= '9' ){
            ip += (int)(c-'0');
        }
        else{
            ip += (int)(c-'a'+10);
        }
    }
    
    int ans[4];
    for(int i=0;i<4;i++){
        ans[3-i] = ip % 256;
        ip >>= 8;
    }

    for(int i=0;i<4;i++){
        printf("%d" , ans[i] );
        if( i==3 ){
            printf("\n");
            return 0;
        }
        printf(".");
    }
    return 0;
}