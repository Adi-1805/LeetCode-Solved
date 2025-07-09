class Solution {
    int m, n;
    int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(x < 0 or y < 0 or x >= m or y >= n) return 0;  
        if(x == m-1 and y == n-1){
            return grid[x][y];
        }
        if(dp[x][y] != -1) return dp[x][y];
        int down = 1e9, right = 1e9;
        if(y+1 < n) down = solve(x, y+1, grid, dp);
        if(x+1 < m) right = solve(x+1, y, grid, dp);
        return dp[x][y] = grid[x][y] + min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, grid, dp);
    }
};