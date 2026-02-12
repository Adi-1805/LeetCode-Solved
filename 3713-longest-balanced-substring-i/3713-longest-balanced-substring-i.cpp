class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++){
                bool check = 1;
                freq[s[j]-'a']++;
                for(int cnt: freq){
                    if(cnt > 0 and cnt != freq[s[j]-'a']){
                        check = 0; break;
                    }
                }
                if(check) maxlen = max(maxlen, j-i+1);
            }
        }
        return maxlen;
    }
};