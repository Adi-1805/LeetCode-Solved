class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), zerocnt = 0, final_product = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zerocnt++;
            else final_product *= nums[i];
        }
        vector<int> ans(n, 0);
        if(zerocnt == 0){
            for(int i = 0; i < n; i++){
                ans[i] = final_product/nums[i];
            }
        }
        else if(zerocnt == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] != 0) ans[i] = 0;
                else ans[i] = final_product;
            }
        }
        return ans;
    }
};