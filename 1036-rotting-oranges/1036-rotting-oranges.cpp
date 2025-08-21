class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int freshOranges = 0;
        queue< pair<pair<int, int>, int> > q;
        vector<vector<int>> vis = grid;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0}); 
                }
                if(grid[i][j] == 1) freshOranges++;
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int time = 0;
        while(!q.empty()){
            auto r = q.front().first.first;
            auto c = q.front().first.second;
            auto t = q.front().second;
            time = max(time, t);
            q.pop();

            for(int i = 0; i < 4; i++){
                auto nr = r + dx[i];
                auto nc = c + dy[i];
                if(nr < n and nr >= 0 and nc < m and nc >= 0 and vis[nr][nc] != 2 and grid[nr][nc] == 1){
                    q.push({{nr, nc}, t+1}); vis[nr][nc] = 2;
                    freshOranges--;
                }
            }
        }

        return (freshOranges == 0) ? time : -1;
    }
};