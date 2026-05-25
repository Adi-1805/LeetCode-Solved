class Solution {
    vector<int> dp;
    int f(int ind, vector<int> &nums){
        if(ind >= nums.size()-1) return 0;
        if(dp[ind] != -1) return dp[ind];
        int ans = 1e9;
        for(int i = 1; i <= nums[ind]; i++){
            ans = min(f(ind+i, nums)+1, ans);
        }
        return dp[ind] = ans;
    }
public:
    int jump(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        return f(0, nums);
    }
};