class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& vec: flights){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }

        vector<int> cost(n, 1e9);
        cost[src] = 0;

        queue<vector<int>> q;
        q.push({0, src, 0}); // {stops, node, cost}

        while(!q.empty()){
            auto vec = q.front();
            int stops = vec[0];
            int node = vec[1];
            int curCost = vec[2];
            q.pop();
            if(stops == k+1) continue;
            for(auto next: adj[node]){
                int nbr = next.first;
                int pesa = next.second;
                if(curCost + pesa < cost[nbr]){
                    cost[nbr] = curCost+pesa;
                    q.push({stops+1, nbr, cost[nbr]});
                }
            }
        }
        return (cost[dst] == 1e9) ? -1: cost[dst];
    }
};