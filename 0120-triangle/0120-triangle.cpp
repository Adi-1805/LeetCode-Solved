class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> lastRow(n,0);
        for(int j=0; j<n; j++) lastRow[j] = triangle[n-1][j];

        for(int row = n-2; row >= 0; row--){
            vector<int> currentRow(n, 0);
            for(int col = row ; col >= 0; col--){
                int down = triangle[row][col] + lastRow[col];
                int diagonallyDown = triangle[row][col] + lastRow[col+1];
                currentRow[col] = min(down,diagonallyDown);
            }
            lastRow = currentRow;
        }
	    return lastRow[0];
    }
};