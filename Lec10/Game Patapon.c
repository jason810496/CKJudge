#include<stdio.h>
#include<string.h>

const char MOVE[100] = "PATA PATA PATA PON";
const char ATK[100]  = "PON PON PATA PON";
const char BACK[100] = "CHAKA CHAKA PATA PON";
const char SPLIT[100] = ".,";

int main () {
    int dis,hp;
    scanf("%d%d\n" , &dis , &hp);
    char raw[50005];
    
    gets(raw);

    char *token;
    char last[500];
    token = strtok(raw,SPLIT);

    int rnd=1;
    int invalid=0;
    while( token != NULL ){

        if( strcmp(token,MOVE) == 0 ){
            dis--;
            if( dis == 0 ){
                printf("NO %d\n", hp );
                return 0;
            }
        }
        else if( strcmp(token,ATK) == 0 ){
            if( dis<=3 ){
                hp--;
                if( hp == 0 ){
                    printf("YES %d\n" , rnd-invalid);
                    return 0;
                }
            }
        }
        else if( strcmp(token,BACK) == 0 ){
            dis++;
        }
        else{
            invalid++;
        }

        strcpy(last,token);
        token = strtok(NULL,SPLIT);

        if( rnd % 10 == 0 && strcmp(last,BACK)!=0 ){
            printf("NO %d\n", hp );
            return 0;
        }
        rnd++;
    }
    printf("NO %d\n", hp );

    return 0;
}

