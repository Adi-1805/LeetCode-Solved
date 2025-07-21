class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n == 1) return s;
        string ans = ""; ans += s[0];
        char prev = s[0]; int consecutiveCnt = (s[0] == s[1]) ? 1 : 0;
        int i = 1;
        while(i < n){
            if(prev == s[i]){
                consecutiveCnt++;
            }else{
                prev = s[i];
                consecutiveCnt = 1;
            }
            if(consecutiveCnt < 3) ans += s[i];
            i++;
        }
        return ans;
    }
};