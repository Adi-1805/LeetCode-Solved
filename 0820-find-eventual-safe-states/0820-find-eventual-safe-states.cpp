class Solution {
    vector<int> topoSort;
    bool cycleDetectWithDfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVis){
        visited[node] = 1;
        pathVis[node] = 1;
        for(int next: graph[node]){
            if(!visited[next]){
                if(cycleDetectWithDfs(next, graph, visited, pathVis)) return true;
            }else if(pathVis[next]){
                return true;
            }
        }
        topoSort.push_back(node);
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, 0), pathVis(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]) cycleDetectWithDfs(i, graph, visited, pathVis); 
        }
        sort(topoSort.begin(), topoSort.end());
        return topoSort;
    }
};