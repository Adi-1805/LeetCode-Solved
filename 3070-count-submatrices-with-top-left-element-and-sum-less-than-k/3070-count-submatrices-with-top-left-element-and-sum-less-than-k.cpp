class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int N = grid.size(), M = grid[0].size();
        int count = 0;
        for(int i = 1; i < N; i++) grid[i][0] += grid[i-1][0];
        for(int j = 1; j < M; j++) grid[0][j] += grid[0][j-1];
        for(int i = 1; i < N; i++){
            for(int j = 1; j < M; j++){
                grid[i][j] = grid[i][j] + grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] <= k) count++;
            }
        }
        return count;
        
    }
};