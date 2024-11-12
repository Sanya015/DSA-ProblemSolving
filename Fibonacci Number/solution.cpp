// RECURSIVE T.C.=O(2^N) S.C.=O(N)
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1)+fib(n-2);
    }
};

// MEMOIZATION T.C.=O(N) S.C.=O(N)+O(N)
class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }

    int fib(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// TABULATION T.C.=O(N) S.C.=O(N)
class Solution {
public:

    int fib(int n) {
        if(n==0) return 0;
        vector<int> dp(n+1, -1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// SPACE OPTIMIZATION T.C.=O(N) S.C.=O(1)
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int prev=0;
        int prev1=1;
        for(int i=2; i<=n; i++){
            int curr=prev+prev1;
            prev=prev1;
            prev1=curr;
        }
        return prev1;
    }
};

