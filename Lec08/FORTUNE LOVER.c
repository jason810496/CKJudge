#include <stdio.h>

void ShowBits(void *a){
    for(int i=31;i>=0;i--){
        printf("%d" , (*(int*)a>>i)&1 );
        if( i%8==0 ) printf(" ");
    }
    printf("\n");
}

int main(void){
    float a,b;
    int *ptr_a = &a;
    int *ptr_b = &b;
    scanf("%f%f" ,&a,&b);

    printf("   ");
    ShowBits(&a);
    printf("+) ");
    ShowBits(&b);
    printf("---------------------------------------\n");
    printf("   ");

    int c = *ptr_a + *ptr_b;
    ShowBits(&c);

    printf("%d + %d = %d\n",(int)a,(int)b,c);
    return 0;
}

