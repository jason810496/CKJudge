#include <stdio.h>

#define N1  0x38E38E38E38E3800LLU
#define N2 0x2AAAAAAAAAAAAAAALLU
#define N3 0x1C71C71C71C71C71LLU
#define MOD 0x7CE66C50E2840000LLU

#define ll unsigned long long 
int main () {
    ll a,b,c;
    scanf("%llu%llu%llu" , &a ,&b,&c);
    ll ans = ( ((a*N1)%MOD + (b*N2)%MOD)%MOD + (c*N3)%MOD ) % MOD ;
    printf("%llu" , ans );
    return 0;
}