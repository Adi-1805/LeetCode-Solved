class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int node: graph[i]){
                adj[node].push_back(i);
            }
        }
  
        vector<int> indegree(n,0);
        queue<int> q;
        vector<int> topo;

        for(int i = 0; i < n; i++){
            for(int node: adj[i]){
                indegree[node]++;
            }
        }

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto next: adj[node]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};