class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // cout << nums.size() << endl;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0; 
        int ans = 0; long long cur = 0;
        while(r < nums.size()){
            long long target = nums[r];
            cur += target;
            while((r-l+1)*target - cur > k){
                cur -= nums[l]; l++;
            }
            ans = max(ans, r-l+1); r++;
        }
        return ans;
    }
};