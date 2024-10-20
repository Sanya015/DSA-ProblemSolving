T.C.=O(V+E) S.C.=O(2V)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> indeg(V);
        for(int i=0; i<V; i++){
            for(auto ele:adj[i]){
                indeg[ele]++;
            }
        }
        queue<int> q;
        int cnt=0;
        for(int i=0; i<V; i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto ele:adj[node]){
                indeg[ele]--;
                if(indeg[ele]==0) q.push(ele);
            }
        }
        if(cnt!=V) return true;
        return false;
        
    }
};
