//RECURSIVE T.C.=O(2^N) S.C.=O(N)
class Solution {
public:

    int solve(int amount, vector<int>& coins, int index){
        if(index<0){
            if(amount==0) return 1;
            return 0;
        }
        int inc=0;
        if(amount>=coins[index]) inc=solve(amount-coins[index], coins, index);
        int ninc=solve(amount, coins, index-1);
        return inc+ninc;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int ans= solve(amount, coins, n-1);
        return ans;
    }
};

//MEMOIZATION T.C.=O(N*M) S.C.=O(N*M)+O(N)
class Solution {
public:

    int solve(int amount, vector<int>& coins, int index, vector<vector<int>>& dp){
        if(index<0){
            if(amount==0) return 1;
            return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int inc=0;
        if(amount>=coins[index]) inc=solve(amount-coins[index], coins, index, dp);
        int ninc=solve(amount, coins, index-1, dp);
        return dp[index][amount]=inc+ninc;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans= solve(amount, coins, n-1, dp);
        return ans;
    }
};

// TABULATION GIVING SOME ISSUES
