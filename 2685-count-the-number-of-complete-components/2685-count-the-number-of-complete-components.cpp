class Solution {
    void bfs(int start, vector<vector<int>>& adj, vector<int>& vis, vector<int>& component){
        queue<int> q; q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            auto node = q.front();
            component.push_back(node);
            q.pop();
            for(int next: adj[node]){
                if(!vis[next]){
                    vis[next] =1;
                    q.push(next);
                }
            }
        }
    }
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &component){
        if(vis[node]) return;
        vis[node] = 1;
        component.push_back(node);
        for(auto &nbr: adj[node]){
            if(!vis[nbr]){
                dfs(nbr, adj, vis, component);
            }
        }

    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto& vec: edges){
            int u = vec[0], v = vec[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> visited(n, 0);
        int result = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                vector<int> component;
                // bfs(i, adjList, visited, component);
                dfs(i, adjList, visited, component);
            
                bool isComplete = 1;
                for(auto it: component){
                    if(adjList[it].size() != component.size()-1){
                        isComplete = false; break;
                    }
                }
                if(isComplete) result++;
            }
        }
        return result;
    }
};