class Solution {
    int dfs(vector<vector<int>> &grid, int k, int i, int j, int m, int n, vector<vector<vector<int>>> &dp) {
        if (i < 0 || j < 0) return INT_MIN;
        if(i == 0 && j == 0) return (k > 0) ? max(0, grid[0][0]) : grid[0][0];

        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int val = grid[i][j];

        int up = dfs(grid, k, i-1, j, m, n, dp);
        int left = dfs(grid, k, i, j-1, m, n, dp);

        int res = INT_MIN;

        if (val >= 0) {
            if (up != INT_MIN) res = max(res, up + val);
            if (left != INT_MIN) res = max(res, left + val);
        } else {
            // take loss
            if (up != INT_MIN) res = max(res, up + val);
            if (left != INT_MIN) res = max(res, left + val);

            // neutralize
            if (k > 0) {
                int up2 = dfs(grid, k-1, i-1, j, m, n, dp);
                int left2 = dfs(grid, k-1, i, j-1, m, n, dp);
                res = max({res, up2, left2});
            }
        }

        return dp[i][j][k] = res;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return dfs(coins, 2, m-1, n-1, m, n, dp);
    }
};