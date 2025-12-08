class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto index = lower_bound(nums.begin(), nums.end(), k);
        return (index - nums.begin());
    }
};