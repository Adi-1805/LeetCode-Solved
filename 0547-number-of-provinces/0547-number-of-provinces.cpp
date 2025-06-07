class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = 1;
        for(auto next: adj[node]){
            if(!vis[next]){ 
                dfs(next, adj, vis);
            }
        }
    }

public:

    vector<vector<int>> convert(vector<vector<int>> a){
        vector<vector<int>> adj(a.size());
        for (int i = 0; i < a.size(); i++){
            for (int j = 0; j < a[i].size(); j++){
                if(a[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        return adj;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj = convert(isConnected);
        vector<bool> visited(adj.size()+1, 0);
        // for each node 
        int count = 0;
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                count++;  
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};