class Solution {
     bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis){
        vis[node] = 1; pathVis[node] = 1;
        for(auto next: adj[node]){
            if(!vis[next]){
                if(dfs(next, adj, vis, pathVis) == true) return true; // we found a cycle
            }else{
                if(pathVis[next]) return true;
            }
        }
        pathVis[node] = 0;

        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& vec: prerequisites){
            adj[vec[1]].push_back(vec[0]); 
        }

        vector<bool> vis(numCourses,0);
        vector<bool> pathVis(numCourses,0);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == true) return false; // we found a cycle
            }
        }
        return true;
    }
};