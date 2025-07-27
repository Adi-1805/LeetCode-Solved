class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int cnt = 0;
        int indicator = -1; // 0 = down, 1 = up;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                if(indicator == 0) cnt++;
                indicator = 1;
            }
            else if(nums[i] < nums[i-1]){
                if(indicator == 1) cnt++;
                indicator = 0;
            }
        }

        return cnt;
    }
};