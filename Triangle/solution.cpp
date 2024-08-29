class Solution {
public:
// Memoization: T.C.=O(M^2) S.C.=O(M^2)+O(m)
    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        int m=triangle.size();
        if(i==m-1) return triangle[i][j];
        int down=INT_MAX, downr=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i+1<=m-1) down=triangle[i][j]+solve(triangle, i+1, j, dp);
        int n=triangle[i].size();
        if(i+1<=m-1) downr=triangle[i][j]+solve(triangle, i+1, j+1, dp);
        return dp[i][j]=min(down, downr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(triangle, 0, 0, dp);
    }
};

// Tabulation: T.C.=O(M^2) S.C.=O(M^2)
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        for(int i=0; i<m; i++){
            dp[m-1][i]=triangle[m-1][i];
        }
        for(int i=m-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down=INT_MAX, downr=INT_MAX;
                down=triangle[i][j]+dp[i+1][j];
                downr=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down, downr);
            }
        }
        return dp[0][0];
    }
};


// SPACE OPTIMIZATION: T.C.=O(M^2) S.C.=O(M)
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int> pre(m, 0);
        for(int i=0; i<m; i++){
            pre[i]=triangle[m-1][i];
        }
        for(int i=m-2; i>=0; i--){
            vector<int> cur(m, 0);
            for(int j=i; j>=0; j--){
                int down=INT_MAX, downr=INT_MAX;
                down=triangle[i][j]+pre[j];
                downr=triangle[i][j]+pre[j+1];
                cur[j]=min(down, downr);
            }
            pre=cur;
        }
        return pre[0];
    }
};
