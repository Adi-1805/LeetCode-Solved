class Solution {
    vector<int> subXor;
    vector<unordered_set<int>> child;
    vector<vector<int>> adj;

    void dfs(int node, int parent, vector<int>& nums){
        subXor[node] = nums[node];
        child[node].insert(node);

        for(int nbr: adj[node]){
            if(nbr != parent){
                dfs(nbr, node, nums);
                subXor[node] ^= subXor[nbr];
                child[node].insert(child[nbr].begin(), child[nbr].end());
            }
        }
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        subXor.resize(n, 0);
        child.resize(n);
        adj.resize(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, nums);

        int totalXor = subXor[0];
        int score = INT_MAX;

        for(int i = 1; i < n; i++){
            for(int j = i+1; j <n; j++){
                int ixor = subXor[i], jxor = subXor[j];
                int val1, val2, val3;

                if(child[i].count(j)){
                    val1 = jxor; val2 = ixor^jxor; val3 = totalXor^ixor;
                }
                else if(child[j].count(i)){
                    val1 = ixor; val2 = jxor^ixor; val3 = totalXor^jxor;
                }
                else{
                    val1 = ixor; val2 = jxor; val3 = totalXor^ixor^jxor;
                }

                score = min( score, (max({val1, val2, val3}) - min({val1, val2, val3})) );
            }
        }
        return score;
    }
};