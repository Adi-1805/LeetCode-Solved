class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            int offset = abs(nums[i]/n) +1;
            result[i] = nums[(i+ offset*n +nums[i])%n];
        }
        return result;
    }
};