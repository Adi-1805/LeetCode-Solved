class Solution {
    int n;
    int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(x < 0 or y < 0 or y > x) return 0;
        if(x == n-1) return grid[x][y];
        if(dp[x][y] != -1) return dp[x][y];
        int down = solve(x+1, y, grid, dp);
        int downRight = solve(x+1, y+1, grid, dp);
        return dp[x][y] = grid[x][y] + min(down, downRight);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, dp);
    }
};