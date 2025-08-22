class Solution {
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &color){
        
        for(int nextNode : graph[node]){
            if(color[nextNode] == -1){
                color[nextNode] = !color[node];
                if(dfs(nextNode, graph, color) == false) return false;
            }
            else if(color[nextNode] == color[node]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // graph is adjacency list  
        int V = graph.size();
        vector<int> colorHashset(V, -1);

        for(int i = 0; i < V; i++){
            if(colorHashset[i] == -1){
                colorHashset[i] = 0; 
                if(dfs(i, graph, colorHashset) == false) return false;
            }
        }
        return true;
    }
};