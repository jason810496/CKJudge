#include <stdio.h>

unsigned long construct(unsigned char parts[16]);

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%lu", construct(parts));

    return 0;
}


unsigned long construct(unsigned char parts[16])
{
    unsigned long l1=0, l2=0;
    for(int i=0;i<8;i++){
        l1*=256;
        l1+=parts[7-i];
        //printf("%lu " , (unsigned long)parts[i] );
    }

    for(int i=0;i<8;i++){
        l2*=256;
        l2+=parts[15-i];
        //printf("%lu " , (unsigned long)parts[15-i] );
    }

    return l1^l2;
}