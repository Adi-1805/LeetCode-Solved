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
        vector<int> prev(n, 0);
        int prevUp = 1e9, prevLeft = 1e9;
        for(int x = 0; x < m; x++){
            vector<int> curr(n, 0);
            for(int y = 0; y < n; y++){
                if(x == 0 and y == 0){
                    curr[0] = grid[0][0];
                    continue; // very important;
                }
                if(y > 0) prevLeft = curr[y-1];
                if(x > 0) prevUp = prev[y];
                curr[y] = grid[x][y] + min(prevUp, prevLeft);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};