class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n == 1) return ans;
        vector<int> prev(2, 1);
        ans.push_back(prev);

        for(int i = 2; i < n; i++){
            vector<int> curr(i+1, 0);
            curr[0] = curr[i] = 1;
            for(int j = 1; j < i; j++){
                curr[j] = prev[j-1] + prev[j];
            }
            prev = curr;
            ans.push_back(prev);
        }

        return ans;
    }
};