class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> end(n,0);
        for(int j=0; j<n; j++) end[j] = triangle[n-1][j];

        for(int row = n-2; row >= 0; row--){
            vector<int> curr(n, 0);
            for(int col = row ; col >= 0; col--){
                int d = triangle[row][col] + end[col];
                int dg = triangle[row][col] + end[col+1];
                curr[col] = min(d,dg);
            }
            end = curr;
        }
	    return end[0];
    }
};