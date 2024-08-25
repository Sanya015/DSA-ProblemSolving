#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // BFS: T.C.=O(N+2E)+O(N) S.C.=O(N)
    bool cycle(int src, vector<int>& vis, vector<int> adj[]){
        queue<pair<int, int>> q;
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty()){
            int node=q.front().first;
            int pre=q.front().second;
            q.pop();
            for(auto ele:adj[node]){
                if(vis[ele]==-1){
                    q.push({ele, node});
                    vis[ele]=1;
                }
                else if(ele!=pre){
                    return true;
                }
                
            }
        }
        return false;
    }
    
    // DFS: T.C.=O(N+2E)+O(N) S.C.=O(N)+O(N)
    bool cycle(int node, int src, vector<int>& vis, vector<int> adj[]){
        vis[node]=1;
        for(auto ele:adj[node]){
            if(vis[ele]==-1){
                if (cycle(ele, node, vis, adj)==true) return true;
            }
            else if(src!=ele) return true;
            
            
        }
        return false;
    }
 
    
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, -1);
        for(int i=0; i<V; i++){
            if(vis[i]==-1){
                bool ans=cycle(i, -1, vis, adj);
                if(ans) return true;
            }
        }
        return false;
    }
};
