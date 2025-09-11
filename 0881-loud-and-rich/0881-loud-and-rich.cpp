class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int v = quiet.size();
        vector<int> ans(v, 0);
        vector<vector<int>> adj(v);
        vector<int> indeg(v, 0);
        vector<int> topo;

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
            topo.push_back(node);
            for(int next: adj[node]){
                if(quiet[ans[node]] < quiet[ans[next]]) ans[next] = ans[node];
                if(--indeg[next] == 0) q.push(next);
            }
        }
        for(int val: topo) cout << val << " ";
        return ans;
    }
};