class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int prevlen = 1, currlen = 1;
        int maxlen = 1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] < nums[i+1]) currlen++;
            else{
                prevlen = currlen;
                currlen = 1;
            }
            if(currlen % 2 == 0) maxlen = max(maxlen, currlen/2);
            maxlen = max(maxlen, min(currlen, prevlen));
        }
        return maxlen;
        
    }
};