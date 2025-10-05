class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorElement = INT_MIN;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > floor(n/2)) majorElement = nums[i];
        }
        return majorElement;
    }
};