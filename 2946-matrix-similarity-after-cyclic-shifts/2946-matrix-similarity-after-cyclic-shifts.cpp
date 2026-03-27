class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int new_n = 0;
        while(new_n < k) new_n += n;
        vector<vector<int>> arr = mat;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i&1) arr[i][(j+k)%n] = mat[i][j];
                else arr[i][(j-k+new_n)%n] = mat[i][j];
            }
        }
        return (arr == mat);
    }
};