class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 1) return nums[0];
        for(int i = 1, j = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
            ans = j;
        }
        return ans;
    }
};