#include <stdio.h>

int main () {
    int n;
    char c , opt;
    scanf("%d" , &n);
    opt = getchar();
    opt = getchar();
    int shift = (opt=='a' ? 1:-1);
    int cur = (n%26+26)%26;
    c = getchar();

    c = getchar();
    while( c!=EOF ){
        if( 'a'<=c && c<= 'z' ){
            int asc = ((c-'a'+cur)%26+26)%26 ;
            c = (char)(asc+'a');
            cur += shift;
        }
        else if( 'A'<=c && c<= 'Z' ){
            int asc = ((c-'A'+cur)%26+26)%26 ;
            c = (char)(asc+'A');
            cur += shift;
        }
        printf("%c",c);
        c = getchar();
    }


    return 0;
}


