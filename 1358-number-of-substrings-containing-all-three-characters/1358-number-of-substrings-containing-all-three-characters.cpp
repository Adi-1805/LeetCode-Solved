class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(); 
        vector<int> fr(3, 0);
        int l = 0, ans = 0;
        for(int r = 0; r < n; r++){
            char ch = s[r];
            fr[ch-'a']++;
            while(fr[0] && fr[1] && fr[2]){
                ans += n - r;
                char lCh = s[l++];
                fr[lCh-'a']--;
            }
        }
        return ans;
    }
};