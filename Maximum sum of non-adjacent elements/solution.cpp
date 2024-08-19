#include <bits/stdc++.h> 

// Recursive(calculated all non-adj subsequences and then took each sub's sum and kept the max)
// Could also do recursion like did in memoization
// T.C.=O(n*2^n) S.C.=O(n)
void solve(vector<int> &nums, int index, vector<int> &sub, int &maxx){
    if(index>=nums.size()){
        int sum=0;
        for(int i=0; i<sub.size(); i++){
            sum+=sub[i];
        }
        maxx=max(maxx, sum);
        return;
    }
    sub.push_back(nums[index]);
    solve(nums, index+2, sub, maxx);
    sub.pop_back();
    solve(nums, index+1, sub, maxx);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int index=0;
    vector<int> sub;
    int maxx=INT_MIN;
    solve(nums, index, sub, maxx);
    return maxx;
}

// Memoisation: T.C.=O(n) S.C.=O(n)+O(n)
int solve(vector<int> &nums, int index, vector<int> &dp){
    if(index==0) return nums[0];
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];
    int inc=nums[index]+solve(nums, index-2, dp);
    int ninc=solve(nums, index-1, dp);
    return dp[index]=max(inc, ninc);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int index=n-1;
    vector<int> dp(n, -1);
    return solve(nums, index, dp);
}

// Tabulation: T.C.=O(n) S.C.=O(n)
int solve(vector<int> &nums, int index, vector<int> &dp){
    int inc=0;
    int ninc=0;
    dp[0]=nums[0];
    for(int i=1; i<nums.size(); i++){
        inc=nums[i];
        if(i>1) inc+=dp[i-2];
        ninc=dp[i-1];
        dp[i]=max(inc, ninc);
    }
    return dp[nums.size()-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int index=0;
    vector<int> dp(n, -1);
    return solve(nums, index, dp);
}

// Space Optimization: T.C.=O(n) S.C.=O(1)
int maximumNonAdjacentSum(vector<int> &nums){
    int prev=nums[0];
    int prev2;
    int curr;
    int inc, ninc;
    for(int i=1; i<nums.size(); i++){
        inc=nums[i];
        if(i>1) inc+=prev2;
        ninc=prev;
        curr=max(inc, ninc);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

