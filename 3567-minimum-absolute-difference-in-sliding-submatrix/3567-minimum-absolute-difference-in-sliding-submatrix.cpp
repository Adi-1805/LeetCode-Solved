class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));
        for(int i = 0; i < m-k+1; i++){
            for(int j = 0; j < n-k+1; j++){
                set<int> st;
                for(int p = i; p < i+k; p++){
                    for(int q = j; q < j+k; q++){
                        st.insert(grid[p][q]);
                    }
                }
                int minabsD = INT_MAX;
                int prev = -1e9;
                for(int x: st){
                    if(prev == -1e9) prev = x;
                    else{
                        minabsD = min(abs(x-prev), minabsD);
                        prev = x;
                    }
                }
                ans[i][j] = (st.size() == 1) ? 0 : minabsD;
            }
        }
        return ans;
    }
};