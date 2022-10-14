#include<stdio.h>

int check(char c){
    return ('a'<=c && c<='z') || ('A'<=c && c<='Z') ;
}
int big(char c ){
    return ('A'<=c && c<='Z');
}
int main () {
    int n;
    int diff = (int)'a' - (int)'A';
    scanf("%d" , &n);
    
    int space = 1;
    char c = getchar();
    while( c != EOF ){
        if( check(c) ){
            if( space ){
                printf("%c" , (char)(big(c) ? c:c-diff) );
                space = 0;
            }
            else{
                printf("%c" , (char)(big(c) ? c+diff:c) );
            }
        }
        else if( c == ' ' ){
            space = 1;
            printf("%c" , c );
        }
        else if( c==',' || c=='.' || c==';' ){
            printf("\n");
            space = 1;
        }

        c = getchar();
    }
    return 0;
}