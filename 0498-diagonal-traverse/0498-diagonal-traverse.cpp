class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        if(n == 1 and m == 0){
            vector<int> result;
            for(int val: mat[0]) result.push_back(val);
            return result;
        }

        vector<vector<int>> diagonals;
        for(int k = 0; k < n-1; k++){
            vector<int> diag; int i = k, j = 0;
            while(i >= 0 and j < m){
                diag.push_back(mat[i--][j++]);
            }
            diagonals.push_back(diag);
        }
        for(int k = 0; k < m; k++){
            vector<int> diag; int j = k, i = n-1;
            while(i >= 0 and j < m){
                diag.push_back(mat[i--][j++]);
            }
            diagonals.push_back(diag);
        }
        
        vector<int> result;
        for(int i = 0; i < diagonals.size(); i++){
            if(i&1){
                reverse(diagonals[i].begin(), diagonals[i].end());
            }
            result.insert(result.end(), diagonals[i].begin(), diagonals[i].end());
        }
        return result;
    }
};