#include <bits/stdc++.h>
using namespace std;

// T.C.=N x M x Log(NxM) + (NxMx4) S.C.=O(NM)
class Solution {
    private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, vector<pair<int, int>>& vec, int row0, int col0){
        int m=grid.size();
        int n=grid[0].size();
        vec.push_back({i-row0, j-col0});
        vis[i][j]=1;
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int nr=dr[k]+i;
            int nc=dc[k]+j;
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==-1 && grid[nr][nc]==1) dfs(grid, vis, nr, nc, vec, row0, col0);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        set<vector<pair<int, int>>> st;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==-1 && grid[i][j]==1){
                    vector<pair<int, int>> vec;
                    dfs(grid, vis, i, j, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
