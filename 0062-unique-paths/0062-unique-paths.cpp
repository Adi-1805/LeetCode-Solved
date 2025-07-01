class Solution {
    vector<vector<int>> dp;
    int solve(int x, int y, int m, int n){
        if(x == m-1 and y == n-1) return 1;
        if(x > m and y > n) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        int down = 0, right = 0;
        if(x+1 < m) down = solve(x+1, y, m, n);
        if(y+1 < n) right = solve(x, y+1, m, n);
        return dp[x][y] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));
        return solve(0, 0, m, n);
    }
};