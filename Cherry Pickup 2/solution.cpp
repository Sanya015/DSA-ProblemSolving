class Solution {
public:

// Recursive: T.C.=O(3^M * 3^M) S.C.=O(M)
int solve(vector<vector<int>>& grid, int i, int j1, int j2){
    int m=grid.size();
    int n=grid[0].size();
    if(j1<0 || j1>=n || j2<0 || j2>=n) return INT_MIN;
    if(i==m-1) {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];

    }
    int maxx=INT_MIN;

    for(int x=-1; x<=1; x++){
        for(int y=-1; y<=1; y++){
            int val=0;
            if(j1==j2) val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            val+=solve(grid, i+1, j1+x, j2+y);
            maxx=max(maxx, val);
        }
    }
    return maxx;
}

    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return solve(grid, 0, 0, n-1);
    }
};

// Memoization: T.C.=O(M*N*N)*9 S.C.=O(M*N*N)+O(M)
int solve(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp){
    int m=grid.size();
    int n=grid[0].size();
    if(j1<0 || j1>=n || j2<0 || j2>=n) return INT_MIN;
    if(i==m-1) {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];

    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxx=INT_MIN;

    for(int x=-1; x<=1; x++){
        for(int y=-1; y<=1; y++){
            int val=0;
            if(j1==j2) val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            val+=solve(grid, i+1, j1+x, j2+y, dp);
            maxx=max(maxx, val);
        }
    }
    return dp[i][j1][j2]=maxx;
}

    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(grid, 0, 0, n-1, dp);
    }
};

// Tabulation: T.C.=O(9MNN) S.C.=O(MNN)
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                if(x==y) dp[m-1][x][y]=grid[m-1][x];
                else dp[m-1][x][y]=grid[m-1][x]+grid[m-1][y];
            }
        }
        for(int x=m-2; x>=0; x--){
            for(int y=0; y<n; y++){
                for(int z=0; z<n; z++){
                    int maxx=INT_MIN;
                    for(int a=-1; a<=1; a++){
                        for(int b=-1; b<=1; b++){
                            int val=0;
                            if(y==z) val=grid[x][y];
                            else val=grid[x][y]+grid[x][z];
                            if(y+a >= 0 && y+a < n && z+b >= 0 && z+b < n) val+=dp[x+1][y+a][z+b];
                            else val+=INT_MIN;
                            maxx=max(maxx, val);
                        }
                    }
                    dp[x][y][z]=maxx;
                }
            }
        }
        return dp[0][0][n-1];
    }
};

// SPACE OPTIMIZATION: T.C.=O(9MNN) S.C.=O(MN)
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> pre(n, vector<int>(n, 0));
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                if(x==y) pre[x][y]=grid[m-1][x];
                else pre[x][y]=grid[m-1][x]+grid[m-1][y];
            }
        }
        for(int x=m-2; x>=0; x--){
            vector<vector<int>> cur(n, vector<int>(n, 0));
            for(int y=0; y<n; y++){
                for(int z=0; z<n; z++){
                    int maxx=INT_MIN;
                    for(int a=-1; a<=1; a++){
                        for(int b=-1; b<=1; b++){
                            int val=0;
                            if(y==z) val=grid[x][y];
                            else val=grid[x][y]+grid[x][z];
                            if(y+a >= 0 && y+a < n && z+b >= 0 && z+b < n) val+=pre[y+a][z+b];
                            else val+=INT_MIN;
                            maxx=max(maxx, val);
                        }
                    }
                    cur[y][z]=maxx;
                }
            }
            pre=cur;
        }
        return pre[0][n-1];
    }
};
