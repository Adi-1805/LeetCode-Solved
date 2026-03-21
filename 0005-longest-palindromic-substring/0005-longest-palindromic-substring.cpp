class Solution {
    bool isPldrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return 0;
        }
        return 1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxlen = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <=1; j++){
                int lo = i, hi = i+j;
                while(lo >= 0 and hi < n and s[lo] == s[hi]){
                    int curlen = hi-lo+1;
                    if(curlen > maxlen){
                        start = lo;
                        maxlen = curlen;
                    }
                    lo--; hi++;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};