class Solution {
    void dfs(int node, vector<vector<int>> &adj, vector<int> &path, vector<vector<int>> &result){
        if(node == adj.size()-1){
            path.push_back(node);
            result.push_back(path); 
            path.pop_back(); 
            return;
        }
        path.push_back(node); 
        for(int nbr: adj[node]){
            dfs(nbr, adj, path, result);
        }
        path.pop_back(); 
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> path; vector<vector<int>> result;
        dfs(0, graph, path, result);
        return result;
    }
};