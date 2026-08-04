class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int curr =  nums[0];
        for(int i = 0; i < nums.size(); curr++, i++){
            if(curr < nums[i]){ ans.push_back(curr); i--; }
        }
        return ans;
    }
};