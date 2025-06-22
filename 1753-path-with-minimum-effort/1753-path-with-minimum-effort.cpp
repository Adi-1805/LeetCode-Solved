class Solution {
    int drow[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dcol[8] = {0, 0, 1, -1, 1, -1, 1, -1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int maxAbsDiff = 0;
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> relDiff(m, vector<int>(n, INT_MAX));
        relDiff[0][0] = heights[0][0];

        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;   
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto pathEffort = pq.top().first;
            auto [row, col] = pq.top().second;
            pq.pop();

            if(row == m-1 and col == n-1) return pathEffort;
            for(int i = 0; i < 4; i++){
                int x = row + drow[i];
                int y = col + dcol[i];
                if(x >= 0 and x < m and y >= 0 and y < n){
                    int newEffort = max(pathEffort, abs(heights[x][y] - heights[row][col]));
                    if(newEffort < relDiff[x][y]){
                        relDiff[x][y] = newEffort;
                        pq.push({newEffort, {x, y}});
                    }

                }
            }
        }
        return 0;
    }
};