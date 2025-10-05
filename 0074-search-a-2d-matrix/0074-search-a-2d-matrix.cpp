class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Relation between linear and 2D Indexing is: (rowIndex * total_number_of_Columns) + columnIndex
        int linearIndex = 0;
        int m = matrix.size(), n = matrix[0].size();
        int linearSize = m*n; 
        int low = 0, high = linearSize - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid/n; // row = currentLinearIndex / numberOfColumns
            int col = mid%n; // col = currentLinearIndex % numberOfColumns

            if(matrix[row][col] < target) low = mid + 1;
            else if(matrix[row][col] > target) high = mid - 1;
            else return true;
            
        } 
        return false;
    }
};