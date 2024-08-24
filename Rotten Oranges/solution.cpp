// T.C.=O(N*M) S.C.=O(N*M)
// My solution
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1){
            if(grid[0][0]==1) return -1;
            else return 0;
        }
        int fresh=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==2){
                    q.push({i, j, 0});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int time=1;
        int ans;
        int con=0;
        while(!q.empty()){
            vector<int> node=q.front();
            q.pop();
            if(node[2]==time) time++;
            int i=node[0];
            int j=node[1];
            if(i>0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1, j, time});
                con++;
            }
            if(i<m-1 && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1, j, time});
                con++;
            }
            if(j>0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i, j-1, time});
                con++;
            }
            if(j<n-1 && grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({i, j+1, time});
                con++;
            }
            ans=node[2];
        }
        if(fresh!=con) return -1;
        if(fresh==0) return 0;
        return ans;
    }
};

//Striver solution
#include<bits/stdc++.h>
using namespace std;
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }

    int main()
    {
        vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
        int rotting = orangesRotting(v);
        cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
    }
