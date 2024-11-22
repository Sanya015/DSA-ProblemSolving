T.C.=O(V+E) S.C.=O(V+E)+O(V)+O(V)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto ele:adj[node]){
                indeg[ele]--;
                if(indeg[ele]==0) q.push(ele);
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};
