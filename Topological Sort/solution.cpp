// DFS: T.C.=O(V+E) S.C.=O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	void dfs(vector<int> adj[], vector<int>& vis, stack<int>& s, int node){
	    vis[node]=1;
	    for(auto ele:adj[node]){
	        if(vis[ele]==-1){
	            dfs(adj, vis, s, ele);
	        }
	        
	    }
	    s.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, -1);
	    stack<int> s;
	    for(int i=0; i<V; i++){
	        if(vis[i]==-1) dfs(adj, vis, s, 0);
	    }
	    vector<int> ans;
	    for(int i=0; i<V; i++){
	        int ele=s.top();
	        s.pop();
	        ans.push_back(ele);
	    }
	    return ans;
	}
};


// BFS(KAHN'S ALGO): T.C.=O(V+E) S.C.=O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indeg(V, 0);
	    for(int i=0; i<V; i++){
	        for(auto ele:adj[i]){
	            indeg[ele]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<int> topo;
	    for(int i=0; i<V; i++){
	        if(indeg[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto ele:adj[node]){
	            indeg[ele]--;
	            if(indeg[ele]==0) q.push(ele);
	        }
	    }
	    return topo;
	    
	}
};

