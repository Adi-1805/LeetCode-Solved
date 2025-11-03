class Solution {
    int f(int curIndex, int prevIndex, vector<int> &nums, vector<vector<int>> &dp){
        if(curIndex == nums.size()) return 0;
        if(dp[curIndex][prevIndex + 1] != -1) return dp[curIndex][prevIndex + 1]; 

        int skip = 0 + f(curIndex + 1, prevIndex, nums, dp), pick = 0;
        if(prevIndex == -1 or nums[curIndex] > nums[prevIndex]){
            pick = 1 + f(curIndex + 1, curIndex, nums, dp);
        } 

        return dp[curIndex][prevIndex + 1] = max(pick, skip); // (prev + 1) to avoid storing at -1 index when prev == -1   
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};