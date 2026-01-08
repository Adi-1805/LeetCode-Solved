class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MIN/2));
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <=m; j++){
                int prod = nums1[i-1]*nums2[j-1];
                int max = prod;
                int possible = prod + dp[i-1][j-1];
                if(possible> max) max = possible;
                if(dp[i-1][j] > max) max = dp[i-1][j];
                if(dp[i][j-1] > max) max = dp[i][j-1];
                dp[i][j] = max;
            }
        }
        return dp[n][m];
    }
};