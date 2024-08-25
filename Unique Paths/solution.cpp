class Solution {
public:

// Recurisev: T.C.=O(2^(M*N)) S.C.=O((M-1)+(N-1))
    int solve(int i, int j, int m, int n){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        return solve(i-1, j, m, n)+solve(i, j-1, m, n); 
    }
    int uniquePaths(int m, int n) {
        return solve(m-1, n-1, m, n);
    }
};

// Memoization: T.C.=O(N*M) S.C.=O(MN)+O((M-1)+(N-1))
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=solve(i-1, j, m, n, dp)+solve(i, j-1, m, n, dp); 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, m, n, dp);
    }
};

// Tabulation: T.C.=O(MN) S.C.=O(MN)
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[0][0]=1;
                else{
                    int up=0, left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};

//Space Optimization: T.C.=O(MN) S.C.=O(N)
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 0);
        for(int i=0; i<m; i++){
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0) cur[j]=1;
                else{
                    int up=0, left=0;
                    if(i>0) up=pre[j];
                    if(j>0) left=cur[j-1];
                    cur[j]=up+left;
                
                }
            }
            pre=cur;
        }
        return pre[n-1];
    }
};

// Mathematical: T.C.=O(M-1) S.C.=O(1)
    int uniquePaths(int m, int n) {
        int tot=n+m-2;
        int r=m-1;
        long long int ans=1;
        for(int i=1; i<=r; i++){
            ans=ans*(tot-r+i)/i;
        }
        return ans;
    }
};
