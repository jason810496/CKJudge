#include <stdio.h>

int main(void){
    int n;
    scanf("%d" , &n);
    char arr[n];
    char c = getchar();

    for(int i=0;i<n;i++){
        scanf("%c" , &c );
        arr[i] = c-'a';
    }
    c = getchar();
    
    c = getchar();
    int idx=0 ,asc;
    while( c!=EOF ){

        if('a' <= c && c<= 'z' ){
            asc = ( (int)c-'a' + arr[idx++] ) % 26 ;
            c = (char)(asc + 'a');
        }
        else if('A' <= c && c<= 'Z' ){
            asc = ( (int)c-'A' + arr[idx++] ) % 26;
            
            c = (char)(asc + 'A');
        }
        
        printf("%c" , c);

        c = getchar();
        if( idx == n ) idx=0;
    }

    return 0;
}



