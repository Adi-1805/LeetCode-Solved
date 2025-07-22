class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int l = 0, r = 0; 
        int consecSum = 0, ans = INT_MIN;
        vector<int> freq(1e4+1, 0);
        while(r < n){
            freq[nums[r]]++; consecSum += nums[r];
            while(freq[nums[r]] > 1){
                consecSum -= nums[l];
                freq[nums[l]]--; l++;
            }
            ans = max(ans, consecSum);
            r++;
        }
        return ans;
    }
};