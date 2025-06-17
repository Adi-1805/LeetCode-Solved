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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,0);
        vector<bool> pathVis(n,0);
        vector<int> topo;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, topo); // we found a cycle
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};