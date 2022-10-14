#include<stdio.h>
#define ui unsigned int 

void SetByte(ui *target,ui byte,int pos){
    *target &= ~(0xFF<<(pos<<3));
    *target |=  (byte<<(pos<<3));
}

ui GetByte(ui target,int pos){
    return (target>>(pos<<3))&0xFF;
}


void check(ui x){
    int arr[32];
    for(int i=0;i<32;i++){
        arr[i] = x&1;
        x>>=1;
    }    
    for(int i=0;i<32;i++){
        printf("%d " ,arr[31-i] );
        if( (i+1) % 8 == 0 ){
            printf(",");
        }
    }
    printf("\n");
}

int main(){
    int d[5] ,total=0;
    ui temp = 0 , N;
    
    scanf("%u" , &N );
    for(int i=1;i<=4;i++){
    	scanf("%d" , &d[i] );
        total += d[i];
        d[i] = 4-d[i];
    }
    // xor d1 th & d2 th , sto 1
    SetByte( &temp , GetByte(N,d[1]) ^ GetByte(N,d[2]) , 3-0);
    // and d2 th & d3 th , sto 2
    SetByte( &temp , GetByte(N,d[2]) & GetByte(N,d[3]) , 3-1);
    // or  d3 th & d1 th , sto 3
    SetByte( &temp , GetByte(N,d[3]) | GetByte(N,d[1]) , 3-2);
    // and tog d4 th , sto 4
    SetByte( &temp , GetByte(N,d[4]) ^ 0xFF , 3-3);

    // rotate right
    for(int i=0;i<total;i++){
    	int last = temp&1;
        temp>>=1;
        temp |= (last<<31);
    }
    
    ui low = temp % (1<<16);
    ui up = temp / (1<<16); 

    printf("%u" , up ^ low );

    return 0;
}