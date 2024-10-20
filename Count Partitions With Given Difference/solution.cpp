// rec and mem are my ways. tab and s.o. are striver

#include <bits/stdc++.h> 

// RECURSIVE T.C.=O(2^N)+O(N) S.C.=O(N)
int solve(vector<int> &arr, int d, int tsum, int index, int subsum){
    if(index<0){
        if(subsum-(tsum-subsum)==d) return 1;
        return 0;
    }
    int inc=solve(arr, d, tsum, index-1, subsum+arr[index]);
    int ninc=solve(arr, d, tsum, index-1, subsum);
    return inc+ninc;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return solve(arr, d, sum, n-1, 0);
}

// MEMOIZATION T.C.=O(N*SUM)+O(N) S.C.=O(N*SUM)+O(N)
int MOD=1e9+7;
int solve(vector<int> &arr, int d, int tsum, int index, int subsum, vector<vector<int>>& dp){
    if(index<0){
        if(subsum-(tsum-subsum)==d) return 1;
        return 0;
    }
    if(dp[index][subsum]!=-1) return dp[index][subsum];
    int inc=solve(arr, d, tsum, index-1, subsum+arr[index], dp);
    int ninc=solve(arr, d, tsum, index-1, subsum, dp);
    return dp[index][subsum]=(inc+ninc)%MOD;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    return solve(arr, d, sum, n-1, 0, dp);
}

// TABULATION T.C.=O(N*K)+O(N) S.C.=O(N*K)
int MOD=1e9+7;
int countPartitions(int n, int d, vector<int> &arr)
{
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    if((sum-d)<0 || (sum-d)%2) return 0;
    int k=(sum-d)/2;
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

// SPACE OPTIMIZATION T.C.=O(N*K)+O(N) S.C.=O(K)
int MOD=1e9+7;
int countPartitions(int n, int d, vector<int> &arr)
{
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    if((sum-d)<0 || (sum-d)%2) return 0;
    int k=(sum-d)/2;
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
