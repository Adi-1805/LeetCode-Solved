class Solution {
    int solve(vector<int>& nums) {
        int n = nums.size();
        // dp.resize(n, 0);
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> arr1, arr2;
        for(int i = 0;  i < n; i++){
            if(i != 0) arr1.push_back(nums[i]);
            if(i != n-1) arr2.push_back(nums[i]);
        }
        return max(solve(arr1), solve(arr2));
    }
};