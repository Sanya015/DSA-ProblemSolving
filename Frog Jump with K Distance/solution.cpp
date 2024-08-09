// Recursive: T.C.=O(k^n) S.C.=O(n)
int solve(int n, int k, vector<int> &height)
{
    if(n==0) return 0;
    int minn=INT_MAX;
    for(int i=1; i<=k; i++){
        int val=INT_MAX;   
        if(n>(i-1)) val=solve(n-i, k, height)+abs(height[n]-height[n-i]);
        minn=min(val, minn);
    }
    return minn;

}
int minimizeCost(int n, int k, vector<int> &height){
return(solve(n-1, k, height));
}

// Memoization: T.C.=O(n*k) S.C.=O(n)+O(n)
int solve(int n, int k, vector<int> &height, vector<int> &dp)
{
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int minn=INT_MAX;
    for(int i=1; i<=k; i++){
        int val=INT_MAX;   
        if(n>(i-1)) val=solve(n-i, k, height, dp)+abs(height[n]-height[n-i]);
        minn=min(val, minn);
    }
    
    
    return dp[n]=(minn);

}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, -1);
return(solve(n-1, k, height, dp));
}

// Tabulation: T.C.=O(n*k) S.C.=O(n)
int solve(int n, int k, vector<int> &height, vector<int> &dp)
{
    dp[0]=0;
    
    for(int i=1; i<=n; i++){
        int minn=INT_MAX;
        for(int j=1; j<=k; j++){
            int val=INT_MAX;   
            if(i>(j-1)) val=dp[i-j]+abs(height[i]-height[i-j]);
            minn=min(val, minn);
        }
        dp[i]=minn;
    }
    return dp[n];
}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, -1);
    return(solve(n-1, k, height, dp));
}

// Space Optimization is not done because in earlier
// problems we were storing in just 2 variables: prev and
// prev1. Here we would need k variables, so kinda a list. 
// So if k=n, then still S.C. will be O(n). 
