class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> pfsum(N+1, vector<int>(M+1, 0));
        int count = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                pfsum[i][j] = grid[i-1][j-1] + pfsum[i-1][j] + pfsum[i][j-1] - pfsum[i-1][j-1];
                if(pfsum[i][j] <= k) count++;
            }
        }
        return count;
    }
};