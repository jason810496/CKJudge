#include<stdio.h>
#include<stdlib.h>
void init(int**** ptr);

#include<stdio.h>
#include<stdlib.h>
void init(int**** ptr);

int main(){
    int ****ptr = malloc(sizeof(int***)*2);
    init(ptr);
    int magic_number;
    long long magic_sum = 0;
    scanf("%d", &magic_number);
    for(int _ = 0; _<2; _++)
        for(int __ = 0; __<2; __++)
            for(int ___ = 0; ___<2; ___++)
                for(int ____ = 0; ____<2; ____++)
                    ptr[_][__][___][____] = magic_number, magic_sum += ptr[_][__][___][____];
    printf("%lld", magic_sum);
}


void init(int**** ptr) {
    for(int _ = 0; _<2; _++){
        ptr[_] = malloc(sizeof(int***)*2);
        for(int __ = 0; __<2; __++){
            ptr[_][__] = malloc(sizeof(int**)*2);
            for(int ___ = 0; ___<2; ___++){
                ptr[_][__][___] = malloc(sizeof(int*)*2);
                for(int ____ = 0; ____<2; ____++){
                    ptr[_][__][___][____] = malloc(sizeof(int));
                }
            }    
        }  
    }  
}