class Solution {
public:

// MEMOIZATION: T.C.=O(N^2) S.C.=O(N^2)+O(N)
// does not work and gives TLE. Tabulation works
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        int m=matrix.size();
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=INT_MAX, upl=INT_MAX, upr=INT_MAX;
        up=matrix[i][j]+solve(matrix, i-1, j, dp); 
        if(j-1>=0) upl=matrix[i][j]+solve(matrix, i-1, j-1, dp); 
        if(j+1<=m-1) upr=matrix[i][j]+solve(matrix, i-1, j+1, dp); 
        return dp[i][j]=min(up, min(upl, upr));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int m=matrix.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        for(int i=0; i<m; i++){
            ans=min(solve(matrix, m-1, i, dp), ans);
        }
        return ans;
    }
};

// TABULATION: T.C.=O(N^2)+O(N) S.C.=O(N^2)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int ans=INT_MAX;
        if(m==1) return matrix[0][0];
        vector<vector<int>> dp(m, vector<int>(m, -1));
        for(int i=0; i<m; i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<m; j++){
                int up=INT_MAX, upl=INT_MAX, upr=INT_MAX;
                up=matrix[i][j]+dp[i-1][j]; 
                if(j-1>=0) upl=matrix[i][j]+dp[i-1][j-1]; 
                if(j+1<=m-1) upr=matrix[i][j]+dp[i-1][j+1]; 
                dp[i][j]=min(up, min(upl, upr));
                if(i==m-1) ans=min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

// SPACE OPTIMIZATION: T.C.=O(N^2) S.C.=O(N)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int ans=INT_MAX;
        if(m==1) return matrix[0][0];
        vector<int> pre(m);
        for(int i=0; i<m; i++){
            pre[i]=matrix[0][i];
        }
        for(int i=1; i<m; i++){
            vector<int> cur(m);
            for(int j=0; j<m; j++){
                int up=INT_MAX, upl=INT_MAX, upr=INT_MAX;
                up=matrix[i][j]+pre[j]; 
                if(j-1>=0) upl=matrix[i][j]+pre[j-1]; 
                if(j+1<=m-1) upr=matrix[i][j]+pre[j+1]; 
                cur[j]=min(up, min(upl, upr));
                if(i==m-1) ans=min(ans, cur[j]);
            }
            pre=cur;
        }
        return ans;
    }
};
