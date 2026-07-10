class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int curcnt = 0, maxcnt = 0;
        for(int r = 0; r < n; r++){
            if(nums[r] == 1) curcnt++;
            else curcnt = 0;
            maxcnt = max(maxcnt, curcnt);
        }
        return maxcnt;
    }
};