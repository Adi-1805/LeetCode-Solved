class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<int, int> fr;
        int maxlen = 0, l = 0;
        for(int r = 0; r < n; r++){
            fr[s[r]]++;
            while(fr[s[r]] > 2){
                fr[s[l]]--;
                if(fr[s[l]] == 0) fr.erase(s[l]); 
                l++;
            }
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};