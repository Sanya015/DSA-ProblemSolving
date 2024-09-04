#include <bits/stdc++.h> 

//RECURSIVE: T.C.=O(2^n) S.C.=O(N)
bool solve(int k, vector<int> &arr, int index){
    if(k==0) return true;
    if(index==0) return (k==arr[0]);
    bool ntake=solve(k, arr, index-1);
    bool take=false;
    if(arr[index]<=k) take=solve(k-arr[index], arr, index-1);
    return take|ntake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(k, arr, n-1);
}

// MEMOIZATION: T.C.=O(N*K) S.C.=O(N)+O(NK)
bool solve(int k, vector<int> &arr, int index, vector<vector<int>>& dp){
    if(k==0) return true;
    if(index==0) return (k==arr[0]);
    if(dp[index][k]!=-1) return dp[index][k];
    bool ntake=solve(k, arr, index-1, dp);
    bool take=false;
    if(arr[index]<=k) take=solve(k-arr[index], arr, index-1, dp);
    return dp[index][k] = take|ntake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(k, arr, n-1, dp);
}


// TABULATION: T.C.=O(N*K) S.C.=O(N*K)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int i=0; i<n; i++){
        dp[i][0]=1;
    }
    dp[0][arr[0]]=1;
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            bool ntake=dp[i-1][j];
            bool take=false;
            if(arr[i]<=j) take=dp[i-1][j-arr[i]];
            dp[i][j]=take|ntake;
        }
    }
    return dp[n-1][k];
}

//SPACE OPTIMIZATION: T.C.=O(NK) S.C.=O(K)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> pre(k+1, 0), cur(k+1, 0);
    pre[0]=cur[0]=1;
    pre[arr[0]]=1;
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            bool ntake=pre[j];
            bool take=false;
            if(arr[i]<=j) take=pre[j-arr[i]];
            cur[j]=take|ntake;
        }
        pre=cur;
    }
    return pre[k];
}
