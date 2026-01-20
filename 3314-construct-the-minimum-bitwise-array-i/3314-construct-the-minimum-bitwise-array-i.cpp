class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            int cur_nums = nums[i];
            for(int j = 1; j < cur_nums; j++){
                if( (j|(j+1)) == cur_nums ){
                    ans[i] = j; break;
                }
            }
            if(ans[i] == 0) ans[i] = -1;
        }
        return ans;
    }
};