class Solution {
public:

// RECURSIVE: T.C.=O(2^MN) S.C.=O(MN)
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        int up=INT_MAX, left=INT_MAX;
        if(i>0) up=grid[i][j]+solve(grid, i-1, j);
        if(j>0) left=grid[i][j]+solve(grid, i, j-1);
        return min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return solve(grid, m-1, n-1);
    }
};


// MEMOIZATION: T.C.=O(MN) S.C.=O(MN)+O(M-1)+(N-1)
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=INT_MAX, left=INT_MAX;
        if(i>0) up=grid[i][j]+solve(grid, i-1, j, dp);
        if(j>0) left=grid[i][j]+solve(grid, i, j-1, dp);
        return dp[i][j]= min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, m-1, n-1, dp);
    }
};

// TABULATION: T.C.=O(MN) S.C.=O(MN)
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else{
                    int up=INT_MAX, left=INT_MAX;
                    if(i>0) up=grid[i][j]+dp[i-1][j];
                    if(j>0) left=grid[i][j]+dp[i][j-1];
                    dp[i][j]= min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// SPACE OPTIMIZATION: T.C.=O(MN) S.C.=O(N)
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> pre(n, 0);
        for(int i=0; i<m; i++){
            vector<int> cur(n);
            for(int j=0; j<n; j++){
                if(i==0 && j==0) cur[0]=grid[0][0];
                else{
                    int up=INT_MAX, left=INT_MAX;
                    if(i>0) up=grid[i][j]+pre[j];
                    if(j>0) left=grid[i][j]+cur[j-1];
                    cur[j]= min(up, left);
                }
            }
            pre=cur;
        }
        return pre[n-1];
    }
};
