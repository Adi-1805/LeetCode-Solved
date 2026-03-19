class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int cursum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            cursum += nums[i];
            // Update the global maximum found so far
            if (cursum > max_sum) {
                max_sum = cursum;
            }
            // If the current sum is negative, it will only decrease 
            // the sum of any future subarray. Reset it to 0.
            if (cursum < 0) {
                cursum = 0;
            }
        }
        
        return max_sum;
    }
};
