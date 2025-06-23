class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& vec: times){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        vector<int> time(n+1, INT_MAX);
        time[0] = 0; time[k] = 0;

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [curTime, node] = pq.top();
            pq.pop();
            for(auto next: adj[node]){
                auto [nbr, t] = next;
                if(curTime + t < time[nbr]){
                    time[nbr] = curTime + t;
                    pq.push({time[nbr], nbr});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < time.size(); i++){
            ans = max(ans, time[i]);
            if(time[i] == INT_MAX) return -1;
        }
        return ans;
    }
};