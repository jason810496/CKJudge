#include<stdio.h>

int main () {
    int n , cur;
    char c[6];
    scanf("%s" , c );
    cur = ((c[0]-'0')*10+(c[1]-'0'))*60 + ((c[3]-'0')*10+(c[4]-'0'));

    scanf("%d" , &n );
    int id[n] , st[n] , ed[n];
    for(int i=0;i<n;i++){
        int h,m,t;
        scanf("%d" , &id[i] );
        scanf("%s%d" , c, &t );
        st[i] = ((c[0]-'0')*10+(c[1]-'0'))*60 + ((c[3]-'0')*10+(c[4]-'0'));
        ed[i] = ((c[0]-'0')*10+(c[1]-'0'))*60 + ((c[3]-'0')*10+(c[4]-'0')) + t ;
    }

    int arrive = 1e9;
    int ans = id[0];
    for(int i=0;i<n;i++){
        if( st[i]>= cur && ed[i] < arrive ){
            arrive = ed[i];
            ans = id[i];
        }
    }

    printf("%d\n" , ans );
    return 0;
}

