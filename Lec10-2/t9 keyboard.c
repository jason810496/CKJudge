#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main() {
  char line[BUFFER_LEN];
  char buffer[LINE_LEN][BUFFER_LEN];
  char *arr[LINE_LEN];

  int count = 0;
  while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
    arr[count] = buffer[count];
    strncpy(buffer[count++], line, BUFFER_LEN - 1);
  }
  convert(arr, count);
  for (int i = 0; i < count; i++) {
    printf("%s", arr[i]);
  }
}

char Map[128][10];
void Init(){
    strcat(Map['a'],"(2)1");
    strcat(Map['b'],"(2)2");
    strcat(Map['c'],"(2)3");

    strcat(Map['d'],"(3)1");
    strcat(Map['e'],"(3)2");
    strcat(Map['f'],"(3)3");

    strcat(Map['g'],"(4)1");
    strcat(Map['h'],"(4)2");
    strcat(Map['i'],"(4)3");

    strcat(Map['j'],"(5)1");
    strcat(Map['k'],"(5)2");
    strcat(Map['l'],"(5)3");

    strcat(Map['m'],"(6)1");
    strcat(Map['n'],"(6)2");
    strcat(Map['o'],"(6)3");

    strcat(Map['p'],"(7)1");
    strcat(Map['q'],"(7)2");
    strcat(Map['r'],"(7)3");
    strcat(Map['s'],"(7)4");

    strcat(Map['t'],"(8)1");
    strcat(Map['u'],"(8)2");
    strcat(Map['v'],"(8)3");

    strcat(Map['w'],"(9)1");
    strcat(Map['x'],"(9)2");
    strcat(Map['y'],"(9)3");
    strcat(Map['z'],"(9)4");
}

void convert(char *arr[], int count){
    Init();

    const char SPLIT[] = " ";
    for(int i=0;i<count;i++){

        char ans[BUFFER_LEN] = {};
        char *token;
        token = strtok(arr[i],SPLIT);
        while(token != NULL ){
            int n = strlen(token);
            if( token[n-1] == '\n' ) n--;
            
            for(int i=0;i<n;i++){
                strcat(ans, Map[ token[i] ] );
            }
            token = strtok(NULL,SPLIT);
            if( token != NULL ) strcat(ans," ");
        }
        strcat(ans,"\n");
        strcpy(arr[i],ans);
    }
}