class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        set<int> set(nums.begin(), nums.end());
        int pos = 0, neg = 0, pSum = 0, nSum = 0;
        for(auto& val: set){
            if(val < 0){
                neg++; nSum += val; 
            } 
            else{
                pos++; pSum += val;
            }
        }

        if(neg == set.size()) return *max_element(nums.begin(), nums.end());
        else return pSum;
    }
};