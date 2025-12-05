class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), count = 0;
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0, right_sum = 0;
        for(int i = 0; i < n-1; i++){
            left_sum += nums[i];
            right_sum = total_sum - left_sum;
            if((left_sum - right_sum) % 2 == 0) count++;
        }
        return count;
    }
};