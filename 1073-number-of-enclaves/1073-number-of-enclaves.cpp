class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(int r, int c, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        vis[r][c] = 1;
        grid[r][c] = -1;
        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and grid[nr][nc] == 1){
                dfs(nr, nc, n, m, grid, vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        // Mark the edge 1s as irreplaceable
        for(int i = 0; i < n; i++) if(grid[i][0] == 1) dfs(i, 0, n, m, grid, visited);
        for(int i = 0; i < n; i++) if(grid[i][m-1] == 1) dfs(i, m-1, n, m, grid, visited);
        for(int j = 0; j < m; j++) if(grid[0][j] == 1) dfs(0, j, n, m, grid, visited);
        for(int j = 0; j < m; j++) if(grid[n-1][j] == 1) dfs(n-1, j, n, m, grid, visited);

        int landCells = 0;
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                if(grid[i][j] == 1) landCells++;
            }
        }
        return landCells;
    }
};