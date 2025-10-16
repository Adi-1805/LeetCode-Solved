class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int curlen = 0, maxlen = 0, l = 0;
        vector<int> alphaHash(256, 0);
        for(int r = 0; r < n; r++){
            alphaHash[s[r]]++;
            curlen++;
            while(alphaHash[s[r]] > 1 and l < n){
                alphaHash[s[l++]]--;
                curlen--;
            }
            maxlen = max(maxlen, curlen);
        }
        return maxlen;
    }
};