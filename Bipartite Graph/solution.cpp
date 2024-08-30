class Solution {
public:

// BFS:
    bool solve(vector<vector<int>>& graph, vector<int> vis, int node) {      
        queue<int> q;
        q.push(node);
        vis[node]=0;
        int col=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto ele:graph[node]){
                if(vis[ele]==-1){
                    q.push(ele);
                    if (vis[node]==0) col=1;
                    else col=0;
                    vis[ele]=col;
                }
                else if(vis[ele]==vis[node]) return false;
                
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(solve(graph, vis, i)==false) return false;
            }
        }
        return true;
    }
};

// DFS:

    bool solve(vector<vector<int>>& graph, vector<int>& vis, int node, int col){
        for(auto ele:graph[node]){
            if(vis[ele]==-1){
                if(col==0) {
                    vis[ele]=1;
                    if(solve(graph, vis, ele, 1)==false) return false;
                }
                else {
                    vis[ele]=0;
                    if(solve(graph, vis, ele, 0)==false) return false;
                }
                
            }
            else if(vis[ele]==col) return false;
            
        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                vis[i]=0;
                if(solve(graph, vis, i, 0)==false) return false;
            }
        }
        return true;
    }
};
