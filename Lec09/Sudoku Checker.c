#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}


void check_sudoku(int (*arr)[NUM]){
    int n = 9;
    int ans[10][10] = { };
    for(int i=0;i<n;i++){
        int cnt[10] = { };
        int pos[10] = { };
        for(int j=0;j<n;j++){
            if( cnt[ arr[i][j] ] ){
                ans[i][j] = 1;
                ans[i][ pos[ arr[i][j] ] ] = 1;
            }
            cnt[ arr[i][j] ] = 1;
            pos[ arr[i][j] ] = j;
        }
    }

    for(int j=0;j<n;j++){
        int cnt[10] = { };
        int pos[10] = { };
        for(int i=0;i<n;i++){
            if( cnt[ arr[i][j] ] ){
                ans[i][j] = 1;
                ans[ pos[ arr[i][j] ] ][j] = 1;
            }
            cnt[ arr[i][j] ] = 1;
            pos[ arr[i][j] ] = i;
        }
    }

    for(int I=0;I<n;I+=3){
        for(int J=0;J<n;J+=3){
            int cnt[10] = { };
            int pos[10] = { };
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if( cnt[ arr[I+i][J+j] ] ){
                        ans[I+i][J+j] = 1;
                        ans[ pos[ arr[I+i][J+j] ]/1000 ][ pos[ arr[I+i][J+j] ]%1000 ] = 1;
                    }
                    cnt[ arr[I+i][J+j] ] = 1;
                    pos[ arr[I+i][J+j] ] = (I+i)*1000+(J+j);
                }
            }
        }
    }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( ans [i][j] ){
                printf("(%d,%d)\n" , i , j );
            }
        }
    }

}