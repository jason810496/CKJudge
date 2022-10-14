#include<stdio.h>

int n;

void top_left(){
	for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            printf((j<=i ? "*":" "));
        }
        printf("\n");
    }
}
void top_right(){
    for(int i=n;i>=1;i--){
        for(int j=n-i;j;j--){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}

void bottom_left(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}
void bottom_right(){
    for(int i=1;i<=n;i++){
    	for(int j=n-i;j;j--){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}
int main () {
    
    int opt;
    scanf("%d%d" , &opt , &n );
    
    switch( opt ) {
        case 1:
            top_left();
            break;
        case 2:
            bottom_left();
            break;
        case 3:
            top_right();
            break;
        case 4:
            bottom_right();
            break;
    }
    return 0;
}