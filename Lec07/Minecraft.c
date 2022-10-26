#include<stdio.h>

int G[21][21];
int ans[21];
int in[21];
int que[200];
int front=0;
int back=0;
int n;

int main () {
    
    scanf("%d" , &n);
    for(int i=1;i<=n;i++){
    	int m;
        scanf("%d",&m);
        G[i][0] = m;
        for(int j=0,x;j<m;j++){
            scanf("%d",&x);
            G[x][i] = 1;
            in[i]++;
        }
    }

    for(int i=1;i<=n;i++){
    	if( G[i][0] == 0){
            que[back++]=i;
            ans[i]=1;
        }
    }

    while( front != back ){
        int cur = que[front++];
        for(int nxt=1;nxt<=n;nxt++){
            if( G[cur][nxt] ){
                if( !--in[nxt] ){
                    que[back++] = nxt;
                }
                ans[nxt]+=ans[cur];
            }
        }
    }
    int result=0;
    for(int i=1;i<=n;i++){
        result+=ans[i];
    }
    printf("%d\n",result);
    return 0;
}