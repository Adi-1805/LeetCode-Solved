class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp; for(char ch: s) mp[ch]++;
        string ans = "", middle = "";
        for(auto it: mp){
            string temp(it.second/2, it.first);
            ans += temp;
           if(it.second & 1) middle += it.first;
        }
        string rev(ans.rbegin(), ans.rend());
        return (ans + middle + rev);
    }
};