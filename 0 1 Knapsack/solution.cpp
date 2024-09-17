#include <bits/stdc++.h> 

// RECURSIVE
// T.C.=2^N S.C.=O(N)
int solve(vector<int> weight, vector<int> value, int maxWeight, int index){
	if(index==0){
		if(weight[0]<=maxWeight) return value[0];
		else return 0;
	} 
	int inc=INT_MIN;
	if(maxWeight>=weight[index]){
		inc=value[index]+solve(weight, value, maxWeight-weight[index], index-1);
	}

	int ninc=solve(weight, value, maxWeight, index-1);	
	return max(inc, ninc);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value, maxWeight, n-1);
}


// MEMOIZATION
// T.C.=O(NW) S.C.=O(NW)+O(N)
int solve(vector<int> weight, vector<int> value, int maxWeight, int index, vector<vector<int>>& dp){
	if(index==0){
		if(weight[0]<=maxWeight) return value[0];
		else return 0;
	} 
	if(dp[index][maxWeight]!=-1) return dp[index][maxWeight];
	int inc=INT_MIN;
	if(maxWeight>=weight[index]){
		inc=value[index]+solve(weight, value, maxWeight-weight[index], index-1, dp);
	}

	int ninc=solve(weight, value, maxWeight, index-1, dp);	
	return dp[index][maxWeight]=max(inc, ninc);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solve(weight, value, maxWeight, n-1, dp);
}


// TABULATION
// T.C.=O(NW) S.C.=O(NW)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
	for(int i=weight[0]; i<=maxWeight; i++){
		dp[0][i]=value[0];
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<=maxWeight; j++){
			int inc=INT_MIN;
			if(weight[i]<=j) inc=dp[i-1][j-weight[i]]+value[i];
			int ninc=dp[i-1][j]+0;
			dp[i][j]=max(inc, ninc);
		}
	}
	return dp[n-1][maxWeight];
}

// SPACE OPTIMIZATION
// T.C.=O(NW) S.C.=O(W) (single array space optimization; we did not use curr array)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0);
	for(int i=weight[0]; i<=maxWeight; i++){
		prev[i]=value[0];
	}
	for(int i=1; i<n; i++){
		for(int j=maxWeight; j>=0; j--){
			int inc=INT_MIN;
			if(weight[i]<=j) inc=prev[j-weight[i]]+value[i];
			int ninc=prev[j]+0;
			prev[j]=max(inc, ninc);
		}
	}
	return prev[maxWeight];
}
