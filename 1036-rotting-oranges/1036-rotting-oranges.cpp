class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshCnt = 0;
        vector<vector<int>> vis(m, vector<int>(n,0)); // int -> bcz we will account for the newly infected cells here by making the row and col intersection 2
        queue <pair<pair<int, int>, int>> q; // {{row, column}, time}
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({{i, j}, 0});
                else if(grid[i][j] == 1) freshCnt++;
            }
        }
        int time = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            time = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = r + drow[i];
                int y = c + dcol[i];
                if(x >= 0 and x < m and y >= 0 and y < n and vis[x][y] != 2 and grid[x][y] == 1){
                    vis[x][y] = 2; freshCnt--;
                    q.push({{x, y}, time+1});
                }
            }
        }
        return (freshCnt == 0) ? time : -1;
    }
};