//striver's approach a lil differebt. he uses 2 variables inc and ninc only. in inc he does not decrement index. that too can be done.

//RECURSIVE T.C.=O(3^MN) S.C.=O(M)
class Solution {
public:

    int solve(vector<int>& coins, int amount, int index){
        if(amount==0) return 0;
        if(index<0) return 1e9;
        int ninc=solve(coins, amount, index-1);
        int inc=INT_MAX;
        int inc_curr=INT_MAX;
        if(amount>=coins[index]) inc=1+solve(coins, amount-coins[index], index-1);
        if(amount>=coins[index]) inc_curr=1+solve(coins, amount-coins[index], index);
        return min(inc, min(ninc, inc_curr));
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=solve(coins, amount, n-1);
        if(ans==1e9) return -1;
        return ans;
    }
};

// MEMOIZATION T.C.=O(MN) S.C.=O(MN)+O(N)
class Solution {
public:

    int solve(vector<int>& coins, int amount, int index, vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(index<0) return 1e9;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int ninc=solve(coins, amount, index-1, dp);
        int inc=INT_MAX;
        int inc_curr=INT_MAX;
        if(amount>=coins[index]) inc=1+solve(coins, amount-coins[index], index-1, dp);
        if(amount>=coins[index]) inc_curr=1+solve(coins, amount-coins[index], index, dp);
        return dp[index][amount]=min(inc, min(ninc, inc_curr));
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans=solve(coins, amount, n-1, dp);
        if(ans==1e9) return -1;
        return ans;
    }
};

TABULATION T.C.=O(NM) S.C.=O(NM)
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        for(int i=0; i<n; i++){
            dp[i][0]=0;
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<amount+1; j++){
                int inc=1e9;
                int inc_curr=1e9;
                int ninc=1e9;
                if(i>0) ninc=dp[i-1][j];
                if(i>0 && j>=coins[i]) inc=1+dp[i-1][j-coins[i]];
                if(j>=coins[i]) inc_curr=1+dp[i][j-coins[i]];
                dp[i][j]=min(inc, min(ninc, inc_curr));
            }
        }
        if(dp[n-1][amount]==1e9) return -1;
        return dp[n-1][amount];
    }
};

SPACE OPTIMIZATION T.C.=O(MN) S.C.=O(M)
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,-1);
        prev[0]=0;
        for(int i=0; i<n; i++){
            vector<int> curr(amount+1);
            for(int j=1; j<amount+1; j++){
                int inc=1e9;
                int inc_curr=1e9;
                int ninc=1e9;
                if(i>0) ninc=prev[j];
                if(i>0 && j>=coins[i]) inc=1+prev[j-coins[i]];
                if(j>=coins[i]) inc_curr=1+curr[j-coins[i]];
                curr[j]=min(inc, min(ninc, inc_curr));
            }
            prev=curr;
        }
        if(prev[amount]==1e9) return -1;
        return prev[amount];
    }
};
