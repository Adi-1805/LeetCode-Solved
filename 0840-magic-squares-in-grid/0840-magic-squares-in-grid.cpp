class Solution {
    bool check(vector<vector<int>>grid, int r, int c){
        // Check distinct cells
        std::set<int> unique_nums;
        for (int i = r; i < r+3; ++i) {
            for (int j = c; j < c+3; ++j) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || unique_nums.count(num)) return false;
                unique_nums.insert(num);
            }
        }
        if (unique_nums.size() != 9) return false; 
        const int magic_sum = 15;
        // Check row sums
        for(int i = r; i < r+3; ++i){
            int row_sum = 0;
            for (int j = c; j < c+3; ++j)  row_sum += grid[i][j];
            if (row_sum != magic_sum) return false;
        }
        // Check column sums
        for (int j = c; j < c+3; ++j) {
            int col_sum = 0;
            for (int i = r; i < r+3; ++i) col_sum += grid[i][j];
            if (col_sum != magic_sum) return false;
        }
        // Check diagonal sums
        int main_diag_sum = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int anti_diag_sum = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
        if (main_diag_sum != magic_sum || anti_diag_sum != magic_sum) return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(rows < 3 or cols < 3) return 0;
        int count = 0;
        for(int i = 0; i < rows-2; i++){
            for(int j = 0; j < cols-2; j++){
                if(check(grid, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};