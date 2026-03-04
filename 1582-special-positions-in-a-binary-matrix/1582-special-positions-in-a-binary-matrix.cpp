class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int result = 0;
        
        for(int i = 0; i < m; i++){
            vector<int> oneCol;
            // Counting number of 1s in each row and storing their colIndexes
            for(int j = 0; j < n; j++) if(mat[i][j] == 1) oneCol.push_back(j);

            // If 1 exists in only one cell of that row, we check the corresponding column for other occurences
            if(oneCol.size() == 1){
                int j = oneCol[0];
                int colCnt1 = 0;
                for(int i = 0; i < m; i++){
                    if(mat[i][j] == 1) colCnt1++;
                }
                // If there is one 1 in that column, we add it to the result
                if(colCnt1 == 1) result++;
            }
        }
        return result;
    }
};