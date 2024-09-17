#include <bits/stdc++.h>

// RECURSIVE
// T.C.=Exponential(more than 2^n) S.C.=O(W)
int solve(int w, vector<int> &profit, vector<int> &weight, int index){
    if(index==0){
        return (w/weight[0])*profit[0];
    }
    int ninc=0+solve(w, profit, weight, index-1);
    int inc=INT_MIN;
    if(w>=weight[index]){
        inc=profit[index]+solve(w-weight[index], profit, weight, index);
    } 

    return max(inc, ninc);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return solve(w, profit, weight, n-1);
}


// MEMOIZATION
// T.C.=O(NW) S.C.=O(NW)+O(N)
int solve(int w, vector<int> &profit, vector<int> &weight, int index, vector<vector<int>>& dp){
    if(index==0){
        return (w/weight[0])*profit[0];
    }
    if(dp[index][w]!=-1) return dp[index][w];
    int ninc=0+solve(w, profit, weight, index-1, dp);
    int inc=INT_MIN;
    if(w>=weight[index]){
        inc=profit[index]+solve(w-weight[index], profit, weight, index, dp);
    } 

    return dp[index][w]=max(inc, ninc);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return solve(w, profit, weight, n-1, dp);
}

// TABULATION
// T.C.=O(NW) S.C.=O(NW)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for(int i=0; i<=w; i++){
        dp[0][i]=(i/weight[0])*profit[0];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<=w; j++){
            int ninc=0+dp[i-1][j];
            int inc=INT_MIN;
            if(weight[i]<=j) inc=profit[i]+dp[i][j-weight[i]];
            dp[i][j]=max(inc, ninc);
        }
    }
    return dp[n-1][w];
}


// SPACE OPTIMIZATION USING 1D ARRAY ONLY
// T.C.=O(NW) S.C.=O(W)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1, 0);
    for(int i=0; i<=w; i++){
        prev[i]=(i/weight[0])*profit[0];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<=w; j++){
            int ninc=0+prev[j];
            int inc=INT_MIN;
            if(weight[i]<=j) inc=profit[i]+prev[j-weight[i]];
            prev[j]=max(inc, ninc);
        }
    }
    return prev[w];
}
