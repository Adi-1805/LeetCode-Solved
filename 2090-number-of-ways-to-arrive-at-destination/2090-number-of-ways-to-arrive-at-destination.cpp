#define ll long long int
class Solution {
    const int M = int(1e9+7);
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj(n);
        for(auto& vec: roads){
            adj[vec[0]].push_back({vec[1], vec[2]});
            adj[vec[1]].push_back({vec[0], vec[2]});
        }
        vector<ll> ways(n, 0);
        ways[0] = 1;
        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue< pair<ll, ll>, vector< pair<ll, ll> > , greater< pair<ll, ll> > > pq;
        pq.push({0, 0});

        while(!pq.empty()){
            ll curDist = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto next: adj[node]){
                ll nbr = next.first;
                ll edgeWt = next.second;
                if((curDist + edgeWt) < dist[nbr]){
                    dist[nbr] = (curDist + edgeWt);
                    pq.push({dist[nbr], nbr});
                    ways[nbr] = ways[node]%M;
                }
                else if(curDist + edgeWt == dist[nbr]){
                    ways[nbr] = (ways[nbr] + ways[node]) %M;
                }
            }
        }

        return ways[n-1];
    }
};