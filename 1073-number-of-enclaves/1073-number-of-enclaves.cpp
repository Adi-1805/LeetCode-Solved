class Solution {
    int m, n;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1 || vis[x][y]) {
            return;
        }
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int r = x + drow[i];
            int c = y + dcol[i];
            dfs(grid, r, c, vis);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1 && !vis[i][0]) dfs(grid, i, 0, vis);
            if (grid[i][n - 1] == 1 && !vis[i][n - 1]) dfs(grid, i, n - 1, vis);
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1 && !vis[0][j]) dfs(grid, 0, j, vis);
            if (grid[m - 1][j] == 1 && !vis[m - 1][j]) dfs(grid, m - 1, j, vis);
        }
        
        int answer = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    answer++;
                }
            }
        }
        return answer;
    }
};