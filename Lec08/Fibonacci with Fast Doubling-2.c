void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
    if( k==0){
        *f2k = 0;
        *f2k1 = 1;
        return;
    }

    fib_fast_doubling(k/2,f2k,f2k1);
    uint64_t a = *f2k;
    uint64_t b = *f2k1;
    uint64_t c , d;
    c = a * (2 * b - a);
    d = (a * a + b * b) ;

    if (k%2==1 ) {
        *f2k = d+c;
        *f2k1 = (d+c)+d;
    }
    else {
        *f2k = c;
        *f2k1 = d;
    }

    return ;
}