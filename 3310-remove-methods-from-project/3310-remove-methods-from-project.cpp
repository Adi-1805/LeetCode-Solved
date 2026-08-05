class Solution {
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto &it: adj[node]){
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        for(auto &it: invocations){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        dfs(k, adj, vis);

        vector<int> rem;
        for(auto &it: invocations){
            int u = it[0], v = it[1];
            if(!vis[u] and vis[v]){
                for(int i=0; i<n; i++) rem.push_back(i);
                return rem;
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]) rem.push_back(i);
        }

        return rem;
    }
};