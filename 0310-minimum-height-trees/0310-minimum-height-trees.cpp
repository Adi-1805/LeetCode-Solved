class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto vec: edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
            indegree[vec[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) if(indegree[i] <= 1) q.push(i);

        while(n > 2){
            int sz = q.size();
            n -= sz;
            while(sz--){
                auto node = q.front();
                q.pop();

                for(int next: adj[node]){
                    indegree[next]--;
                    if(indegree[next] == 1) q.push(next);
                }
            }
        }
        
        vector<int> roots;
        while(!q.empty()){
            roots.push_back(q.front());
            q.pop();
        }
        return roots;
    }
};