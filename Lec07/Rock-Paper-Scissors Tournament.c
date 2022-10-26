#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int lg(int n){
    int cnt=0;
    while(n){
        n>>=1;
        cnt++;
    }
    return cnt;
}

int win(char str[],int a,int b,char cmp){
    if( str[a] == str[b] ){
        if( cmp == 'b' ) return b;
        else return a;
    }
    if( str[a] =='r' ){
        if( str[b]=='p' ){
            return b;
        }
        else if( str[b]=='s'){
            return a;
        }
    }
    else if( str[a] == 'p' ){
        if( str[b]=='r' ){
            return a;
        }
        else if( str[b] == 's' ){
            return b;
        }
    }
    else if( str[a] == 's' ){
        if( str[b] == 'p' ){
            return a;
        }
        else if( str[b] == 'r' ){
            return b;
        }
    }
}
int main () {
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);

    int L = lg(n)-1;
    char judge[L+1];
    scanf("%s",judge);

    int last[n];
    for(int i=0;i<n;i++){
        last[i]=i;
    }
    for(int k=0,sz=n;k<L;k++,sz/=2){
        int idx=0;
        for(int i=0;i<sz;i+=2){
            last[idx++]=win(str,last[i],last[i+1],judge[k]);
        }
    }
    printf("%d\n",last[0]+1);
    
    return 0;
}

