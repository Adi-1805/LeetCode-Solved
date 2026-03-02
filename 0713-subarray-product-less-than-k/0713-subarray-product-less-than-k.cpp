class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int prod = 1, ans = 0;
        while(r < n){
            prod *= nums[r];
            while(prod >= k and l < n and nums[l] < prod){
                prod /= nums[l]; l++;
            }
            if(prod < k) ans += (r-l+1);
            r++;
        }
        return ans; 
    }
};