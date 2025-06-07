class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int initColor = image[sr][sc];
        vector<vector<int>> vis = image;
        while(!q.empty()){
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            vis[sr][sc] = color;
            for(int i = 0; i < 4; i++){
                auto x = r + drow[i];
                auto y = c + dcol[i];
                if(x >= 0 and x < m and y >= 0 and y < n and vis[x][y] != color and image[x][y] == initColor){
                    vis[x][y] = color; 
                    q.push({x, y});
                }
            }
        }
        return vis;
    }
};