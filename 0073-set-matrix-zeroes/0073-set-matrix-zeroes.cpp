class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool has0InCol1 = 0, has0InRow1 = 0; 

        // Using first row and first column for the matrix and FLAG ARRAYS to keep track of rest of the rows/columns that contain zero (in my previous submission I used sets to store the index values os those rows and columns that had 0) 
        for(int i = 0; i < m; i++){      
            for(int j = 0; j < n ; j++){

                // keeping track of 1st col and 1st row separately
                if(i == 0 and matrix[i][j] == 0){ has0InRow1 = 1;}
                if(j == 0 and matrix[i][j] == 0){ has0InCol1 = 1;}

                // marking the FLAG ARRAYS
                if( i != 0 and j != 0 and matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                
            }
        }
        
        // Converting to zeroes
        for(int i = 1; i < m; i++){      
            for(int j = 1; j < n ; j++){
                if( (matrix[i][0] == 0 || matrix[0][j] == 0) ){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Making sure the first row and first column also zero up if they contain zero
        if(has0InCol1) for(int i = 0; i < m; i++) matrix[i][0] = 0;
        if(has0InRow1) for(int j = 0; j < n; j++) matrix[0][j] = 0;
    }
};