class NumMatrix {
    vector<vector<int>> pfsum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        /* Prepping a 2-D prefix sum matrix*/
        int row = matrix.size(), col = (row > 0) ? matrix[0].size() : 0;
        pfsum.resize(row+1, vector<int>(col + 1, 0));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                pfsum[i][j] = matrix[i-1][j-1] + pfsum[i-1][j] + pfsum[i][j-1] - pfsum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (pfsum[row2+1][col2+1] - pfsum[row1][col2+1] - pfsum[row2+1][col1] + pfsum[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */