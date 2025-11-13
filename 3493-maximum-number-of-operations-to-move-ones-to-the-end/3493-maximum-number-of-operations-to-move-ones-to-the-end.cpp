class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, onecnt = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == '1' and s[i] == '0'){
                onecnt++;
                ans += onecnt;
            }
            else if(s[i-1] == '1') onecnt++;
        }
        if(s[s.size()-1] == 0) ans += onecnt;
        return ans;
    }
};