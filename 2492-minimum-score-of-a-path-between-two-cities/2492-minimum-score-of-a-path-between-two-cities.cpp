class Solution {
    void dfs(int i, int n, vector<vector<pair<int, int>>> &g, vector<bool> &vis, int &min_score){
        vis[i] = 1;
        for(auto nbr: g[i]){
           int b = nbr.first, wt = nbr.second;
           min_score = min(min_score, wt);
           if(!vis[b]) dfs(b, n, g, vis, min_score);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& road : roads) {
            int a = road[0], b = road[1], distance = road[2];
            graph[a].push_back({b, distance});
            graph[b].push_back({a, distance});
        }
        vector<bool> vis(n+1, 0);
        int ans = INT_MAX;
        dfs(1, n, graph, vis, ans);
        return ans;
    }
};