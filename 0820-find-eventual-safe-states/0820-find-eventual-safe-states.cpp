class Solution {
    /* KAHN'S ALGORITHM */
    void KahnAlgo(int V, vector<vector<int>>& adj, vector<int>& topoSort){
        queue<int> q; 
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(int verti: adj[i]) indegree[verti]++;
        }
        
        for(int v = 0; v < V; v++) if(indegree[v] == 0) q.push(v);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(int next: adj[node]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> topoSort;
        vector<vector<int>> revAdj(V);
        for(int i = 0; i < V; i++){
            for(int verti: graph[i]){
                revAdj[verti].push_back(i);
            }
        }
        
        KahnAlgo(V, revAdj, topoSort);
        sort(topoSort.begin(), topoSort.end());
        return topoSort;
    }
};