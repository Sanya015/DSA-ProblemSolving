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

// TABULATION T.C.=O(N*M) S.C.=O(N*M)

class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<double>> dp(n, vector<double>(amount+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=amount; j++){
                double inc=0;
                if(j>=coins[i]) inc=dp[i][j-coins[i]];
                double ninc=dp[i-1][j];
                dp[i][j]=inc+ninc;

            }
        }
        return dp[n-1][amount];
    }
};

//SPACE OPTIMIZATION T.C.=O(N*M) S.C.=O(M)
class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<double> prev(amount+1, 0);
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) prev[i]=1;
        }
        for(int i=1; i<n; i++){
            vector<double> curr(amount+1, 0);
            for(int j=0; j<=amount; j++){
                double inc=0;
                if(j>=coins[i]) inc=curr[j-coins[i]];
                double ninc=prev[j];
                curr[j]=inc+ninc;

            }
            prev=curr;
        }
        return prev[amount];
    }
};
