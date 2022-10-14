#include<stdio.h>
#include<stdlib.h>

#define A 4.0
#define AP 4.3
#define AM 3.7
#define B 3.0
#define BP 3.3
#define BM 2.7
#define C 2.0
#define CP 2.3
#define CM 1.7
#define F 0.0

void clear(char *token,int *ptr){
    token[0] = token[1] = '\0';
    *ptr = 0;
}

float value(char *token){
    if( token[1] =='\0' ){
        if( token[0] == 'A' ) return A;
        else if( token[0] == 'B' ) return B;
        else if( token[0] == 'C' ) return C;
        else if( token[0] == 'F' ) return F;
    }
    else{
        if( token[0] == 'A' ){
            if( token[1] =='+' ) return AP;
            else return AM;
        }
        else if( token[0] == 'B' ){
            if( token[1] =='+' ) return BP;
            else return BM;
        }
        else if( token[0] == 'C' ){
            if( token[1] =='+' ) return CP;
            else return CM;
        }
    }

    return F;
}
void calculate(char *token,float *total_credit,float *cur_credit,float *ans){
    float v = value(token);
    *ans += (*cur_credit) * v;
    *cur_credit = 0.0;
}
int isDigit(char c){
    return ('0'<=c && c<= '9');
}
int toDigit(char c){
    return c-'0';
}

int main () {
    float total_credit = 0;
    float cur_credit = 0;
    float ans = 0 ;

    char c = getchar();
    char token[3];
    int ptr=0;

    while( c != '\n' ){
        if( isDigit(c) ){
            calculate(token,&total_credit,&cur_credit,&ans);
            total_credit+=toDigit(c);
            cur_credit+=toDigit(c);
            clear(token,&ptr);
        }
        else{
            token[ptr++]=c;
        }
        c = getchar();
    }
    calculate(token,&total_credit,&cur_credit,&ans);

    printf("%.2f" , ans/total_credit);
    return 0;
}
