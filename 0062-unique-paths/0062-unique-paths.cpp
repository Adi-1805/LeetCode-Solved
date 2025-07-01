class Solution {
    // int solve(int x, int y, int m, int n){
    //     if(x == m-1 and y == n-1) return 1;
    //     if(x > m or y > n) return 0;
    //     if(dp[x][y] != -1) return dp[x][y];
    //     int down = 0, right = 0;
    //     if(x+1 < m) down = solve(x+1, y, m, n);
    //     if(y+1 < n) right = solve(x, y+1, m, n);
    //     return dp[x][y] = down + right;
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 and j == 0) dp[0][0] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};