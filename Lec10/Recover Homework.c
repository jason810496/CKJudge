#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}

int Valid(char *str){
    int len=strlen(str);
    if( len == 1 ) return ( 'a'<=str[0]&&str[0]<='z' || 'A'<=str[0]&&str[0]<='Z' );
    if( len > 21 ) return 0;
    len--;
    for(int i=0;i<len;i++){
        if( !( 'a'<=str[i]&&str[i]<='z' || 'A'<=str[i]&&str[i]<='Z' ) ){
            return 0;
        }
    }
    
    if( str[len]=='.' || str[len]==',' || str[len]=='!' || str[len]=='?' || 'a'<=str[len]&&str[len]<='z' || 'A'<=str[len]&&str[len]<='Z' ) return 1;
    return 0;
}

void recovery(char *homework) {
    const char SPLIT[] = " \n";
    char *token;
    char *tmp;
    char ans[MAX_LEN] = { };

    token = strtok(homework,SPLIT);
    while( token!= NULL ){
        if( Valid(token) ){
            strcat(ans,token);
            strcat(ans," ");
        }
        token = strtok(NULL,SPLIT);
    }
    strcpy(homework,ans);
}