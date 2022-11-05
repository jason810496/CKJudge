int max(int a,int b){
	return (a>b ? a:b);
}

int maxChandy(int size) {
   int dp[size];
   dp[0] = array[0];
   dp[1] = max(array[0],array[1]);
   
    for(int i=2;i<size;i++){
    	dp[i] = max(dp[i-1],dp[i-2]+array[i] );
    }
    
    return dp[size-1];
}

