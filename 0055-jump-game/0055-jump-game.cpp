class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxInd = 0;
        for(int i = 0; i < n; i++){
            if(i > maxInd) return false;
            else maxInd = max(maxInd, i+nums[i]);
        }
        return (maxInd >= n-1) ? true: false;
    }
};