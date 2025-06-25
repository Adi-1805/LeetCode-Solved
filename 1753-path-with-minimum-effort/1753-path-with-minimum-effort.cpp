class Solution {
    int drow[4] = {0, 0, -1, 1};
    int dcol[4] = {-1, 1, 0 ,0};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        effort[0][0] = 0;
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, 0, 0}); // {diff, row, col}

        while(!pq.empty()){
            int diff = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if(row == m-1 and col == n-1) return diff;
            for(int i = 0; i < 4; i++){
                int x = row + drow[i];
                int y = col + dcol[i];
                if(x >= 0 and y >=0 and x < m and y < n){
                    int newEffort = max(diff, abs(heights[row][col]-heights[x][y]));
                    if(newEffort < effort[x][y]){
                        effort[x][y] = newEffort;
                        pq.push({newEffort, x, y});
                    }
                }
            }
        }
        return 0;
    }
};