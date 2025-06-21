class Solution {
    int drow[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dcol[8] = {0, 0, 1, -1, 1, -1, 1, -1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // if the source or the destination cell value is 1 then we cannot start or reach respectively (the )
        // checking src cell is necessary, the destination cell will be dealt by the code 
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        dist[0][0] = 0;

        priority_queue< pair<int, pair<int, int>>, vector< pair<int, pair<int, int>> >, greater< pair<int, pair<int, int>>> > pq;
        pq.push({1, {0, 0}});

        while(!pq.empty()){
            auto curDist = pq.top().first;
            auto [row, col] = pq.top().second;
            pq.pop();
            for(int i = 0; i < 8; i++){
                int x = row + drow[i];
                int y = col + dcol[i];
                if(x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 0 and curDist + 1 < dist[x][y]){
                    dist[x][y] = curDist+1;
                    pq.push({dist[x][y], {x, y}});
                }
            }
            if(row == n-1 and col == n-1) return curDist;
        }
        return -1;
    }
};