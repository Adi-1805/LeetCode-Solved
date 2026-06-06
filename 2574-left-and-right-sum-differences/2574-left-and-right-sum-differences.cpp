class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int right = total, left = 0;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            right = total-left-nums[i];
            ans[i] = abs(left-right);
            left += nums[i];
        }
        return ans;
    }
};