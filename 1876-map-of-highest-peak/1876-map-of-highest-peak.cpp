class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q; // {row, col}
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j]){
                    q.push({i, j});
                    vis[i][j] = 1; 
                    height[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                auto nr = r + dx[i];
                auto nc = c + dy[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc]){
                    q.push({nr, nc}); vis[nr][nc] = 1;
                    height[nr][nc] = height[r][c]+1; 
                }
            }
        }

        return height;
    }
};