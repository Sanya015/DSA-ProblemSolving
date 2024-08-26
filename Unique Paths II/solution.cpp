class Solution {
public:

// Memoization: T.C.=O(MN) S.C.=O(MN)+O(M-1)+(N-1)
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp){
        if(obstacleGrid[0][0]==0 && i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=0, left=0;
        if(obstacleGrid[i][j]==0) up=solve(obstacleGrid, i-1, j, dp);
        if(obstacleGrid[i][j]==0) left=solve(obstacleGrid, i, j-1, dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if(m==1 && n==1){
            if(obstacleGrid[0][0]==1) return 0;
            return 1;
        }
        return solve(obstacleGrid, m-1, n-1, dp);
    }
};

// Tabulation: T.C.=O(MN) S.C.=O(MN)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if(m==1 && n==1){
            if(obstacleGrid[0][0]==1) return 0;
            return 1;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0 && obstacleGrid[0][0]==0) dp[0][0]=1;
                else{
                    int up=0, left=0;
                    if(i>0 && obstacleGrid[i][j]==0) up=dp[i-1][j];
                    if(j>0 && obstacleGrid[i][j]==0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];

    }
};

// Space Optimization: T.C.=O(MN) S.C.=O(N)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> pre(n, 0);
        
        if(m==1 && n==1){
            if(obstacleGrid[0][0]==1) return 0;
            return 1;
        }
        
        for(int i=0; i<m; i++){
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0 && obstacleGrid[0][0]==0) cur[0]=1;
                else{
                    int up=0, left=0;
                    if(i>0 && obstacleGrid[i][j]==0) up=pre[j];
                    if(j>0 && obstacleGrid[i][j]==0) left=cur[j-1];
                    cur[j]=up+left;
                }
            }
            pre=cur;
        }
        return pre[n-1];

    }
};
