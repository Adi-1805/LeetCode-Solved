class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;

        int initColor = image[sr][sc];
    
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc}); 
        vis[sr][sc] = 1;
        ans[sr][sc] = color;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                auto nr =  r + dx[i]; auto nc = c + dy[i];
                if(nr >= 0 and nr < n and nc >= 0 and nr < m and image[nr][nc] == initColor and !vis[nr][nc]){
                    vis[nr][nc] = 1; q.push({nr, nc});
                    ans[nr][nc] = color;
                }
            }
        }

        return ans;
    }
};