#include<stdio.h>

int G[105][105];
double out[105];
double ans[105] , cur[105];
int main () {
    int n;
    scanf("%d" , &n );
    for(int i=0;i<n;i++){
        int x;
        while( scanf("%d" , &x ) ){
            if( x==-1) break;
            G[i][x] = 1;
            out[i]++;
        }
    }

    for(int i=0;i<n;i++){
        ans[i] = (double)1/(double)n;
    }

    int t=100;
    char per = '%';
    while( t-- ){
        for(int i=0;i<n;i++){
            cur[i] = ans[i];
            ans[i]=0;
        }
        for(int i=0;i<n;i++){

            double wt = cur[i] / out[i];
            for(int nxt=0;nxt<n;nxt++){
                if( G[i][nxt]){
                    ans[nxt]+=wt;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%.2lf%c ",ans[i]*100.0,per);
    }
    printf("\n");
    return 0;
}

