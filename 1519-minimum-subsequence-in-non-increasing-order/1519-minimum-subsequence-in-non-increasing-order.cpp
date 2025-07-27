class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        vector<int> ans;

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        int sum = 0;

        for(int i = 0; i < n; i++){ 
            if(sum > (totalSum - sum)) break;
            sum += nums[i];
            ans.push_back(nums[i]);
        } 
        
        return ans;
    }
};