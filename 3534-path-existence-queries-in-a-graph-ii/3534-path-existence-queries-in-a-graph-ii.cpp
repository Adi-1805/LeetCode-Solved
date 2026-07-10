class Solution {
public:
    static const int LOG = 18;
    int up[LOG][100005];
    int pos[100005];
    pair<int, int> arr[100005];

    // Returns minimum jumps required to reach v from u
    int getJumps(int u, int v){
        if(u == v) return 0;
        // Can reach in one jump
        if(up[0][u] >= v) return 1;
        // Cannot reach
        if(up[LOG - 1][u] < v) return -1;

        int jumps = 0;
        // Binary Lifting
        for(int j = LOG - 1; j >= 0; j--){
            if(up[j][u] < v){
                jumps += (1 << j); u = up[j][u];
            }
        }
        return jumps + 1;
    }

    vector<int> pathExistenceQueries( int n,vector<int>& nums,int maxDiff,vector<vector<int>>& queries ) {
        // Store value with original index
        for(int i = 0; i < n; i++){
            arr[i] = {nums[i], i};
        }
        sort(arr, arr + n);

        // Position of original indices in sorted array
        for(int i = 0; i < n; i++){
            pos[arr[i].second] = i;
        }

        // Sliding Window
        int r = 0;
        for(int l = 0; l < n; l++){
            while(r + 1 < n && arr[r + 1].first - arr[l].first <= maxDiff) r++;
            up[0][l] = r;
        }

        // Build Binary Lifting Table
        for(int j = 1; j < LOG; j++){
            for(int i = 0; i < n; i++){
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        // Answer Queries
        vector<int> ans;
        for(auto &q: queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];
            if(u > v) swap(u, v);
            ans.push_back(getJumps(u, v));
        }

        return ans;
    }
};