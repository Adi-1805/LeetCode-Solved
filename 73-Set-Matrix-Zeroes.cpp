class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n ; j++){
                if(i == 0 or j == 0){
                    if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j<n ; j++){
                    if(matrix[i][0] == 0 or matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};