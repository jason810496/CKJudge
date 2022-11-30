void solve(int *A, int *B, int *op_cnt){
    int cnt=0;
	for(int i=0;i<N;i++){
    	if( B[i] > A[i] ){
        	A[i] = B[i];
            cnt++;
        }
    }
    *op_cnt = cnt;
}