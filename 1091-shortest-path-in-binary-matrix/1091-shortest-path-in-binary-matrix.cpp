class Solution {
    using pii = pair<int, int>;
    int dx[8] = {-1,1,0,0,-1,-1, 1,1};
    int dy[8] = {0,0,-1,1,-1,1,1,-1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        pq.push({1, {0, 0}}); dist[0][0] = 0;
        while(!pq.empty()){
            int curDist = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == n-1 and c == n-1) return curDist;
            for(int i = 0; i < 8; i++){
                int x = r + dx[i], y = c + dy[i];
                if(x >= 0 and x < n and y >= 0 and y < n and curDist +1 < dist[x][y] and grid[x][y] == 0){
                    dist[x][y] = curDist +1;
                    pq.push({dist[x][y], {x, y}});
                }
            }
        }
        return -1;
    }
};