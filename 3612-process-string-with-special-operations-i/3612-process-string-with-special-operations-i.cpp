class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string res;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '*'){
                if (res.length()) res.pop_back();
            }
            else if(ch == '#') res += res;
            else if(ch == '%') reverse(res.begin(), res.end()); 
            else if(ch >= 'a' && ch <= 'z') res.push_back(ch);
        }
        return res;
    }
};