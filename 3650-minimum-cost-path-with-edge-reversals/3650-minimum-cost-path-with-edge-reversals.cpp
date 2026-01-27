class Solution {
    vector<int> djikstra(int V, vector<vector<pair<int, int>>>& adj, int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        dist[src] = 0; pq.push({0, src});
        while(!pq.empty()){
            auto cur_dist = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            for(auto &next: adj[node]){
                int nbr = next.first, d = next.second;
                if(cur_dist + d < dist[nbr]){
                    dist[nbr] = cur_dist +d;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return dist;
    }
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto e: edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }
        vector<int> distances = djikstra(n, adj, 0);
        return (distances[n-1] == 1e9) ? -1 : distances[n-1];
    }
};