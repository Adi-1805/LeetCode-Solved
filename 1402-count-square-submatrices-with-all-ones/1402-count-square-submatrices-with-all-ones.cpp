class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum = 0;

        int rows = matrix.size();
        if (rows == 0)
            return 0;
        int columns = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(columns, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (matrix[row][col] == 1) {
                    if (row == 0 || col == 0) {
                        dp[row][col] = 1;
                    } else {
                        dp[row][col] =
                            1 + std::min({dp[row - 1][col], dp[row][col - 1],
                                          dp[row - 1][col - 1]});
                    }
                }

                sum += dp[row][col];
            }
        }

        return sum;
    }
};