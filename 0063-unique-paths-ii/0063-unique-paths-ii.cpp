class Solution {
    int m, n;
    int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(x < 0 or y < 0 or x >= m or y >= n) return 0;
        if(grid[x][y] == 1) return 0;
        if(x == m-1 and y == n-1) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = solve(x+1, y, grid, dp) + solve(x, y+1, grid, dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(0, 0, obstacleGrid, dp);
    }
};