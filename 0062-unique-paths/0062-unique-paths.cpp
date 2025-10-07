class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> nextRow(n, 0);

        for(int row = m-1; row >= 0 ; row--){
            vector<int> currRow(n, 0);

            for(int col = n-1; col >= 0; col--){
                if(row == m-1 and col == n-1){ currRow[col] = 1; continue; }
                
                int waysDown = 0, waysRight = 0;
                if(row < m-1) waysDown  = nextRow[col];
                if(col < n-1) waysRight = currRow[col+1];

                currRow[col] = waysDown + waysRight;
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};