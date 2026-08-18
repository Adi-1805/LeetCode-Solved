class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k) return *max_element(nums.begin(), nums.end());
        int freq[51] = {0};
        for(int x : nums) freq[x]++;
        if(k == 1){
            for(int i = 50; i >= 0; --i) if(freq[i] == 1) return i;
            return -1;
        }
        int missing = -1;
        if(freq[nums[0]] == 1) missing = max(missing, nums[0]);
        if(freq[nums[n-1]] == 1)missing = max(missing, nums[n-1]);
        return missing;
    }
};