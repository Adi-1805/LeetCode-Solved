class Solution {
    int m, n;
    // int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(x < 0 or y < 0 or x >= m or y >= n) return 0;  
    //     if(x == m-1 and y == n-1){
    //         return grid[x][y];
    //     }
    //     if(dp[x][y] != -1) return dp[x][y];
    //     int down = 1e9, right = 1e9;
    //     if(y+1 < n) down = solve(x, y+1, grid, dp);
    //     if(x+1 < m) right = solve(x+1, y, grid, dp);
    //     return dp[x][y] = grid[x][y] + min(down, right);
    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int up = 1e9, left = 1e9;
        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(x == 0 and y == 0){
                    dp[0][0] = grid[0][0];
                    continue; // very important;
                }
                if(y > 0) up = dp[x][y-1];
                if(x > 0) left = dp[x-1][y];
                dp[x][y] = grid[x][y] + min(up, left);
            }
        }
        return dp[m-1][n-1];
    }
};