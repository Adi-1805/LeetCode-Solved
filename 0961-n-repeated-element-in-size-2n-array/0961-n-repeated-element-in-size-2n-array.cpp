class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[(i+1)%n] or nums[i] == nums[(i+2)%n]) return nums[i];
        }
        return -1;
    }
};