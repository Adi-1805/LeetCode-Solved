class Solution {
    vector<int> dp;
    // int solve(vector<int>& arr, int ind){
    //     if(ind < 0) return 0;
    //     if(ind == 0) return arr[ind];
    //     if(dp[ind] != -1) return dp[ind];
    //     int pick = arr[ind] + solve(arr, ind-2);
    //     int not_pick = 0 + solve(arr, ind-1);
    //     return dp[ind] = max(pick, not_pick);
    // }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp.resize(n, 0);
        // return solve(nums, n-1);

        // dp[0] = nums[0]; 
        int prev2 = 0, prev = nums[0], curr = 0;
        int pick = INT_MIN, not_pick = INT_MIN;
        for(int i = 1; i < n; i++){
            pick = (i-2 >= 0) ? nums[i] + prev2 : nums[i] + 0;
            not_pick = prev;
            curr = max(pick, not_pick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
        // return dp[n-1];
    }
};