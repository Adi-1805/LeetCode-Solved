class Solution {
    int m, n;
    int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(x < 0 or y < 0 or x >= m or y >= n) return 0;  
        if(x == 0 and y == 0){
            return grid[x][y];
        }
        if(dp[x][y] != -1) return dp[x][y];
        int up = 1e9, left = 1e9;
        if(y-1 >= 0) up = grid[x][y] + solve(x, y-1, grid, dp);
        if(x-1 >= 0) left = grid[x][y] + solve(x-1, y, grid, dp);
        return dp[x][y] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};