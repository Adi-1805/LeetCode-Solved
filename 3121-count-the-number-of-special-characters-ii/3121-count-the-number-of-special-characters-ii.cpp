class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            if(islower(s[i])) mp[s[i]] = i;
            else if(isupper(s[i]) && mp.find(s[i]) == mp.end()) mp[s[i]] = i;
        }
        int ans = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp.count(c) && mp.count(c-'a'+'A') && mp[c] < mp[c-'a'+'A']) ans++;
        }
        return ans;
    }
};