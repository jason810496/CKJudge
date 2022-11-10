#include<stdio.h>

int n;
int G[105][105];
int ans[105][105];

void DFS(int cur,int id){
    ans[id][cur] = 1;
    for(int nxt=1;nxt<=n;nxt++){
        if( G[cur][nxt] ){
            DFS(nxt,id);
        }
    }
}

int main () {
    scanf("%d" , &n );
    getchar();

    int cur;
    while( scanf("%d" , &cur) ){
        if( cur == 0 ) break;
        int c = getchar() , x=0;

        while( scanf("%d" , &x) ){
            G[cur][x]=1;
            c = getchar();
            if( c == '\n' ) break;
        }
    }

    for(int i=1;i<=n;i++){
        DFS(i,i);
    }

    for(int i=1;i<=n;i++){
        printf("%d -> ",i);
        for(int j=1;j<=n;j++){
            if( ans[i][j] ){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    return 0;
}

