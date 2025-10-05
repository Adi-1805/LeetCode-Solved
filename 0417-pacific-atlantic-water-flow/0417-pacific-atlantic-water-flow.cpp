
class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis){
        if(i<0 || j<0 || j>=grid[0].size() || vis[i][j] == true) return;

        vis[i][j] = true;

        for(int x = 0; x < 4; x++){
            int nx = i + dx[x];
            int ny = j + dy[x];
            if(nx < grid.size() && ny < grid[0].size() && nx >= 0 && ny >=0 && vis[nx][ny] == false && grid[i][j] <= grid[nx][ny]){
                dfs(grid, nx, ny, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> v;
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> vis1(r, vector<bool>(c, false));
        vector<vector<bool>> vis2(r, vector<bool>(c, false));
        for(int i =0; i<r; i++){
            dfs(heights, i, 0, vis1);
        }
        for(int i =0; i<c; i++){
            dfs(heights,0, i, vis1);
        }
        for(int i =0; i<r; i++){
            dfs(heights, i, c-1, vis2);
        }
        for(int i =0; i<c; i++){
            dfs(heights,r-1, i, vis2);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis1[i][j]==true&&vis2[i][j]==true){
                    v.push_back({i,j});
                }
            }
        }
        return v;
    }
};