class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans = mat;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
               if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
               }
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front().first;
            auto dist = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = r + drow[i];
                int y = c + dcol[i];
                if(x >= 0 and x < m and y >= 0 and y < n and !vis[x][y] ){
                   q.push({{x,y}, dist+1}); vis[x][y] = 1; 
                   ans[x][y] = dist+1;
                }
            }
        }
        return ans;
    }
};