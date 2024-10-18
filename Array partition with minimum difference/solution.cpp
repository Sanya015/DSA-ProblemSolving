// recursive and memoized solutions are my logics. tabulated and space optimized solutions are striver's logic.

#include<bits/stdc++.h>

// RECURSIVE
T.C.=O(N)+O(2^N) S.C.=O(2^N)
int solve(vector<int>& arr, int index, int tsum, int sub){
	if(index<0){
		return abs(sub-(tsum-sub));
	}
	int inc=solve(arr, index-1, tsum, sub+arr[index]);
	int ninc=solve(arr, index-1, tsum, sub);
	return min(inc, ninc);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}
	return solve(arr, n-1, sum, 0);
}

// MEMOIZATION
T.C.=O(N)+O(N*Sum) S.C.=O(N*SUM)+O(N*SUM)
int solve(vector<int>& arr, int index, int tsum, int sub, vector<vector<int>>& dp){
	if(index<0){
		return abs(sub-(tsum-sub));
	}
	if(dp[index][sub]!=-1) return dp[index][sub];
	int inc=solve(arr, index-1, tsum, sub+arr[index], dp);
	int ninc=solve(arr, index-1, tsum, sub, dp);
	return dp[index][sub]=min(inc, ninc);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}
	vector<vector<int>> dp(n, vector<int>(sum+1, -1));
	return solve(arr, n-1, sum, 0, dp);
}

// TABULATION T.C.=O(N)+O(N)+O(N*SUM) S.C.=O(N*SUM)
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}
	vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
	for(int i=0; i<n; i++){
		dp[i][0]=1;
	}
	if(arr[0]<=sum) dp[0][arr[0]]=1;
	for(int i=1; i<n; i++){
		for(int j=1; j<sum+1; j++){
			bool take=false;
			if(arr[i]<=j) take=dp[i-1][j-arr[i]];
			bool ntake=dp[i-1][j];
			dp[i][j]=take||ntake; 
		}
	}
	int ans=INT_MAX;
	for(int i=0; i<(sum/2)+1; i++){
		if(dp[n-1][i]) ans=min(ans, abs(i-(sum-i)));
	}
	return ans;

}

// SPACE OPTIMIZATION T.C.=O(N)+O(N)+O(N*SUM) S.C.=O(SUM)
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}
	vector<bool> prev(sum+1, 0);
	prev[0]=1;
	if(arr[0]<=sum) prev[arr[0]]=1;
	for(int i=1; i<n; i++){
		vector<bool> curr(sum+1, 0);
		curr[0]=true;
		for(int j=1; j<sum+1; j++){
			bool take=false;
			if(arr[i]<=j) take=prev[j-arr[i]];
			bool ntake=prev[j];
			curr[j]=take||ntake; 
		}
		prev=curr;
	}
	int ans=INT_MAX;
	for(int i=0; i<(sum/2)+1; i++){
		if(prev[i]) ans=min(ans, abs(i-(sum-i)));
	}
	return ans;

}

