class Solution {
    int f(int m, int n, int row, int col, vector<vector<int>> &dp){
        if(row < 0 or row >= m or col < 0 or col >= n) return 0;
        if(row == m-1 and col == n-1) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        int waysDown = f(m, n, row+1, col, dp);
        int waysRight = f(m, n, row, col+1, dp);

        return dp[row][col] = waysDown + waysRight;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int row = m-1; row >= 0 ; row--){
            for(int col = n-1; col >= 0; col--){
                if(row == m-1 and col == n-1){ dp[row][col] = 1; continue; }
                
                int waysDown = 0, waysRight = 0;
                if(row < m-1) waysDown  = dp[row+1][col];
                if(col < n-1) waysRight = dp[row][col+1];

                dp[row][col] = waysDown + waysRight;
            }
        }
        return dp[0][0];
    }
};