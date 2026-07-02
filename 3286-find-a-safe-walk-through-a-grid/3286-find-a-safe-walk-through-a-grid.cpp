class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<vector<int>>> dp;

    bool dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& vis, int health) {

        if (x < 0 || x >= m || y < 0 || y >= n || health <= 0 || vis[x][y]) return false;
        if (x == m - 1 && y == n - 1) return health > grid[x][y];
        if (dp[x][y][health] != -1) return dp[x][y][health];

        vis[x][y] = true;
        bool ans = false;
        for (int i = 0; i < 4 && !ans; i++) {
            ans |= dfs(x + dx[i], y + dy[i], m, n, grid, vis, health - grid[x][y]);
        }

        vis[x][y] = false;
        return dp[x][y][health] = ans;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        return dfs(0, 0, m, n, grid, vis, health);
    }
};