// T.C.=O(N+2E) S.C=O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void solve(vector<int> adj[], vector<int>& dfs, int node, vector<int>& vis){
      vis[node]=1;
      dfs.push_back(node);
      for(auto ele:adj[node]){
          if(vis[ele]==-1){
              solve(adj, dfs, ele, vis);
          }
          
      }
  }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, -1);
        vector<int> dfs;
        solve(adj, dfs, 0, vis);
        return dfs;
        
    }
};
