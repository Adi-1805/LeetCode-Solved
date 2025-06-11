class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis, vector<int>& topo){
        vis[node] = 1; pathVis[node] = 1;
        for(auto next: adj[node]){
            if(!vis[next]){
                if(dfs(next, adj, vis, pathVis, topo) == true) return true; // we found a cycle
            }else{
                if(pathVis[next]) return true;
            }
        }
        topo.push_back(node);
        pathVis[node] = 0;

        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& vec: prerequisites){
            adj[vec[1]].push_back(vec[0]); 
        }

        vector<bool> vis(numCourses,0);
        vector<bool> pathVis(numCourses,0);
        vector<int> topo;

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis, topo) == true) return {}; // we found a cycle
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};