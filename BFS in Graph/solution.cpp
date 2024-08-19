//T.C.=O(N)+O(2E) S.C.=O(3N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        queue<int> q;
        vector<int> vis(V, 0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto ele:adj[node]){
                if(vis[ele]!=1) q.push(ele);
                vis[ele]=1;
            }
        }
        return bfs;
    }
};
