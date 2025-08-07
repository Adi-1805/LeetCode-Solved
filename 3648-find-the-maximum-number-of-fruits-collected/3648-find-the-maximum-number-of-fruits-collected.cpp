class Solution {
    int n, steps;
    vector<vector<int>> dp;
    int dfs1(int x, int y, vector<vector<int>>& grid){
        if(x < 0 or x >= n or y < 0 or y >= n) return 0;
        if(x == n-1 and y == n-1) return 0;
        if(x == y or x > y) return -1e9;
        if(dp[x][y] != -1) return dp[x][y];

        int way2 = grid[x][y] + dfs1(x+1, y, grid);
        int way1 = grid[x][y] + dfs1(x+1, y-1, grid);
        int way3 = grid[x][y] + dfs1(x+1, y+1, grid);
        
        return dp[x][y] = max({way1, way2, way3});
    }
    int dfs2(int x, int y, vector<vector<int>>& grid){
        if(x < 0 or x >= n or y < 0 or y >= n) return 0;
        if(x == n-1 and y == n-1) return 0;
        if(x == y or y > x) return -1e9;
        if(dp[x][y] != -1) return dp[x][y];

        int way2 = grid[x][y] + dfs2(x, y+1, grid);
        int way3 = grid[x][y] + dfs2(x+1, y+1, grid);
        int way1 = grid[x][y] + dfs2(x-1, y+1, grid);
        
        return dp[x][y] = max({way1, way2, way3});
    }
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        int final_sum = 0;
        dp.resize(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            final_sum += grid[i][i];
            grid[i][i] = 0; dp[i][i] = 0;
        }

        final_sum += dfs1(0, n-1, grid);
        final_sum += dfs2(n-1, 0, grid);

        return final_sum;
    }
};