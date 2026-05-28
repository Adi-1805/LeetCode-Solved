class Solution {
public:
    int dfs(int ind, vector<int>& arr, int d, vector<int>& dp) {
        if(dp[ind] != -1) return dp[ind];
        int way1 = 1, way2 = 1;
        for(int x = 1; x <= d && (ind-x) >= 0; x++){
            if(arr[ind] > arr[ind-x]){
                way1 = max(way1, 1+dfs(ind-x, arr, d, dp));
            }else break;
        }
        for(int x = 1; x <= d && (ind+x) < arr.size(); x++){
            if(arr[ind] > arr[ind+x]){
                way2 = max(way2, 1+dfs(ind+x, arr, d, dp));
            }else break;
        }
        return dp[ind] = max(way1, way2);
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;
        for(int i = 0; i < n; i++) ans = max(ans, dfs(i, arr, d, dp));
        return ans;
    }
};