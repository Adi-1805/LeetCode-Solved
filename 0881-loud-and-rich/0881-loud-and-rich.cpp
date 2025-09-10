class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int v = quiet.size();
        vector<int> ans(v, INT_MAX);
        vector<vector<int>> adj(v);
        vector<int> indeg(v, 0);

        for(auto pair: richer){
            int u = pair[0], v = pair[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;
        for(int i = 0; i < indeg.size(); i++){
            ans[i] = i;
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(int next: adj[node]){
                if(ans[next] == INT_MAX || quiet[ans[node]] < quiet[ans[next]]) ans[next] = ans[node];
                if(--indeg[next] == 0) q.push(next);
            }
        }

        return ans;
    }
};