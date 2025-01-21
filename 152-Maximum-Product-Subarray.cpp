class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxProduct = 0;

        for(int i = 1, imax = ans, imin = ans; i < nums.size(); i++){
            if(nums[i] < 0) swap(imin, imax);
            imax = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin*nums[i]);
            ans = max(ans, imax);
        }
        return ans;
    }
};