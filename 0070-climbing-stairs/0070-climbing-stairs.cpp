class Solution {
public:
    // RECURSION WITH MEMOIZATION
    int DP(int n, vector<int>& dp){
        if(dp[n] != -1) return dp[n];
        return dp[n] = DP(n-1, dp) + DP(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(46, -1);
        dp[0] = 0; dp[1] = 1; dp[2] = 2;
        return DP(n, dp);
    }
};