class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
               if(grid[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
               }
            }
        }

        while(!q.empty()){
            auto r = q.front().first.first;
            auto c = q.front().first.second;
            auto dist = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = r + drow[i];
                int y = c + dcol[i];
                if(x >= 0 and x < m and y >= 0 and y < n and !vis[x][y]){
                    q.push({{x,y}, dist+1}); vis[x][y] = 1;
                    ans[x][y] = dist+1;
                }
            }
        }
        return ans;
    }
};