class Solution {
public:

//T.C.=O(MN) S.C.=O(MN)

    void bfs(int i, int j, vector<vector<int>>& vis, int m, int n, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j]=1;
        while(!q.empty()){
            pair<int, int> node=q.front();
            int x=node.first;
            int y=node.second;
            q.pop();
            if(x > 0 && grid[x-1][y] == '1' && vis[x-1][y] == -1) { q.push({x-1, y}); vis[x-1][y] = 1; }
            if(x < m-1 && grid[x+1][y] == '1' && vis[x+1][y] == -1) { q.push({x+1, y}); vis[x+1][y] = 1; }
            if(y > 0 && grid[x][y-1] == '1' && vis[x][y-1] == -1) { q.push({x, y-1}); vis[x][y-1] = 1; }
            if(y < n-1 && grid[x][y+1] == '1' && vis[x][y+1] == -1) { q.push({x, y+1}); vis[x][y+1] = 1; }
            // if(x > 0 && y > 0 && grid[x-1][y-1] == '1' && vis[x-1][y-1] == -1) { q.push({x-1, y-1}); vis[x-1][y-1] = 1; }
            // if(x > 0 && y < n-1 && grid[x-1][y+1] == '1' && vis[x-1][y+1] == -1) { q.push({x-1, y+1}); vis[x-1][y+1] = 1; }
            // if(x < m-1 && y > 0 && grid[x+1][y-1] == '1' && vis[x+1][y-1] == -1) { q.push({x+1, y-1}); vis[x+1][y-1] = 1; }
            // if(x < m-1 && y < n-1 && grid[x+1][y+1] == '1' && vis[x+1][y+1] == -1) { q.push({x+1, y+1}); vis[x+1][y+1] = 1; }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); 
        vector<vector<int>> vis(m, vector<int>(n, -1));
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==-1 && grid[i][j]=='1'){ 
                    bfs(i, j, vis, m, n, grid);
                    ans++;}
                
            }
        }
        return ans;
    }
};

// here we are considering 4 neighbours only but at some places we might be considering all 8 neighbours
// shortcut for neighbours rather than mentioning each separately as above:
// for(int drow=-1; drow<=1; drow++){
//   for(int dcol=-1; dcol<=1; dcol++){
//     int nrow=row+drow;
//     int ncol=col+dcol;
//     //check conditions as above
//   }
// }
