class Solution {
    vector<int> dp;
    int solve(vector<int>& arr, int ind){
        if(ind < 0) return 0;
        if(ind == 0) return arr[ind];
        if(dp[ind] != -1) return dp[ind];
        int pick = arr[ind] + solve(arr, ind-2);
        int not_pick = 0 + solve(arr, ind-1);
        return dp[ind] = max(pick, not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return solve(nums, n-1);
    }
};