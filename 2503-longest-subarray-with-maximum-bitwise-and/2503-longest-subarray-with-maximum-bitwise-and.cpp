class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAnd = 0, ans = 0, maxlen = 0;
        for (int num :nums){
            if(maxAnd < num){
                maxAnd = num; ans = maxlen = 0;
            }
            if(maxAnd == num) maxlen++;
            else maxlen = 0;
            ans = max(ans, maxlen);
        }
        return ans;
    }
};