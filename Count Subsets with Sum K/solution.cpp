// RECURSIVE T.C.=O(2^N) S.C.=O(N)
int solve(vector<int>& arr, int k, int sum, int index) {
	if(index<0) {
		if(sum==k) return 1;
		else return 0;
	}
	int inc=solve(arr, k, sum+arr[index], index-1);
	int ninc=solve(arr, k, sum, index-1);
	return inc+ninc;
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	return solve(arr, k, 0, n-1);
}

// MEMOIZATION T.C.=O(N*K) S.C.=O(N*K)+O(N)
int MOD=1e9+7;
int solve(vector<int>& arr, int k, int sum, int index, vector<vector<int>>& dp) {
	if(index<0) {
		if(sum==k) return 1;
		else return 0;
	}
	if(dp[index][sum]!=-1) return dp[index][sum];
	int inc=0;
	if(sum+arr[index]<=k) inc=solve(arr, k, sum+arr[index], index-1, dp);
	int ninc=solve(arr, k, sum, index-1, dp);
	return dp[index][sum]=(inc+ninc)%MOD;
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return solve(arr, k, 0, n-1, dp);
}

// TABULATION T.C.=O(N*K) S.C.=O(N*K)
int MOD=1e9+7;
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	dp[0][0]=1;
	if(arr[0]<=k) dp[0][arr[0]]=1;
	if(arr[0]==0) dp[0][0]=2;
	for(int i=1; i<n; i++){
		for(int j=0; j<k+1; j++){
			int inc=0;
			if(arr[i]<=j) inc=dp[i-1][j-arr[i]];
			int ninc=dp[i-1][j];
			dp[i][j]=(inc+ninc)%MOD;
		}
	}
	return (dp[n-1][k]);
}


// SPACE OPTIMIZATION T.C.=O(N*K) S.C.=O(K)
int MOD=1e9+7;
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<int> prev(k+1, 0);
	prev[0]=1;
	if(arr[0]<=k) prev[arr[0]]=1;
	if(arr[0]==0) prev[0]=2;
	for(int i=1; i<n; i++){
		vector<int> curr(k+1, 0);
		for(int j=0; j<k+1; j++){
			int inc=0;
			if(arr[i]<=j) inc=prev[j-arr[i]];
			int ninc=prev[j];
			curr[j]=(inc+ninc)%MOD;
		}
		prev=curr;
	}
	return prev[k];
}
