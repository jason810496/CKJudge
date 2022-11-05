#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
    uint64_t a=1;
    uint64_t b=1;
    uint64_t t;

    int n = k*2+1;
    for(int i=2;i<n;i++){
        t = b;
        b += a;
        a = t;
    }
    *f2k = a;
    *f2k1= b;

    return ;
}