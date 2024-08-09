#include <bits/stdc++.h> 
// Recursive: T.C.=O(2^n) S.C.=O(n)
int solve(int n, vector<int> &heights)
{
    if(n==0) return 0;
    int two=INT_MAX;
    int one=solve(n-1, heights)+abs(heights[n]-heights[n-1]);
    if(n>1) two=solve(n-2, heights)+abs(heights[n]-heights[n-2]);
    return (min(one, two));

}
int frogJump(int n, vector<int> &heights){
return(solve(n-1, heights));
}

// Memoization: T.C.=O(n) S.C.=O(n)+O(n)
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if(n==0) return 0;
    
    if(dp[n]!=-1) return dp[n];
    int two=INT_MAX;
    int one=solve(n-1, heights, dp)+abs(heights[n]-heights[n-1]);
    if(n>1) two=solve(n-2, heights, dp)+abs(heights[n]-heights[n-2]);
    return dp[n]=(min(one, two));

}
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, -1);
return(solve(n-1, heights, dp));
}

// Tabulation: T.C.=O(n) S.C.=O(n)
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    dp[0]=0;
    for(int i=1; i<=n; i++){
        int one=dp[i-1]+abs(heights[i]-heights[i-1]);
        int two=INT_MAX;
        if(i>1) two=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(one, two);
    }
    return dp[n];
}
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, -1);
    return(solve(n-1, heights, dp));
}

// Space Optimization: T.C.=O(n) S.C.=O(1)
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    int prev=0;
    int prev1=0;
    int cur=0;
    for(int i=1; i<=n; i++){
        int one=prev+abs(heights[i]-heights[i-1]);
        int two=INT_MAX;
        if(i>1) two=prev1+abs(heights[i]-heights[i-2]);
        cur=min(one, two);
        prev1=prev;
        prev=cur;
    }
    return prev;
}
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, -1);
    return(solve(n-1, heights, dp));
}
