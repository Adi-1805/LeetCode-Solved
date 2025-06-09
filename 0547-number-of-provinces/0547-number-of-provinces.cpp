class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = 1;
        for(auto next: adj[node]){
            if(!vis[next]) dfs(next, adj, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n  = isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<bool> visited(n, 0);
        for(int node = 0; node < adjList.size(); node++){
            if(!visited[node]){
                cnt++;
                dfs(node, adjList, visited);
            }
        }
        return cnt;
    }
};