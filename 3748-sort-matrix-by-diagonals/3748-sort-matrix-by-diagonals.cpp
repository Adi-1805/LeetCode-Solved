class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int k = m-1; k > 0; k--){ // Upper Triangle
            vector<int> diag; int j = k, i = 0;
            while(i < n and j < m){
                int cell = grid[i++][j++];
                diag.push_back(cell);
            }
            sort(diag.begin(), diag.end()); // sort - ascending
            j = k; i = 0;
            int ind = 0;
            while(i < n and j < m and ind < diag.size()){
               ans[i++][j++] = diag[ind++];
            }
            
        }
        for(int k = 0; k < n; k++){ // Lower Triangle
            vector<int> diag; int i = k, j = 0;
            while(i < n and j < m){
                int cell = grid[i++][j++];
                diag.push_back(cell);
            }
            sort(diag.rbegin(), diag.rend()); // sort - descending
            i = k; j = 0;
            int ind = 0;
            while(i < n and j < m and ind < diag.size()){
               ans[i++][j++] = diag[ind++]; 
            }  
        }
        
        return ans;
    }
};