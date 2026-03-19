class Solution {
    void recur(int ind, vector<int> &nums, vector<int> &permut, vector<vector<int>> &result){
        if(ind >= nums.size()){
            result.push_back(permut);
            return;
        }

        // Skip duplicate elements
        int next_ind = ind + 1;
        while (next_ind < nums.size() && nums[next_ind] == nums[ind]) {
            next_ind++;
        }

        recur(next_ind, nums, permut, result); // skip
        permut.push_back(nums[ind]); 

        recur(ind+1, nums, permut, result); // pick
        permut.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permut;
        sort(nums.begin(), nums.end());
        recur(0, nums, permut, result);
        return result;
    }
};