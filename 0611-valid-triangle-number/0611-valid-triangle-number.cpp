class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 2; i < n; i++){
            int l = 0, r = i-1;
            while(l < r){
                if(nums[l]+nums[r]>nums[i]){
                    result += r-l;
                    r--;
                }
                else l++;
            }
        }
        return result;
    }
};