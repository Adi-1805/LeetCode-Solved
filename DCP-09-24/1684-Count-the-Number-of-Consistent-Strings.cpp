class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> v(26,0);
        for(char c: allowed) v[c-'a'] = 1;
        int ans = 0;
        for(string& s: words){
            bool flag = 1;
            for(char c : s){
                if(v[c-'a'] == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};