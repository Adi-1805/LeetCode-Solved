class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int l = 0, r = l + k -1; l < nums.size() and r < nums.size(); l++, r++){
            diff = min(diff, nums[r] - nums[l]);
        }
        return (diff == INT_MAX) ? 0 : diff;
    }
};