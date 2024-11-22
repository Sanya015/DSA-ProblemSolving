class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        int cnt=0;
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            ans.push_back(node);
            for(auto ele:adj[node]){
                indeg[ele]--;
                if(indeg[ele]==0) q.push(ele);
            }
        }
        if(cnt==numCourses) return ans;
        return {};
    }
};
