class Solution {
    string rotateRight(string s, int b){
        int n = s.size();
        string ans = "";
        ans = ans + s.substr(n-b, b) + s.substr(0, n-b);
        return ans;
    }
    string addA(string s, int a){
        int n = s.size();
        for(int i = 1; i < n; i+=2){
            int digit = s[i] - '0';
            digit = (digit + a) % 10;
            s[i] = digit + '0';
        }
        return s;
    }
    void solve(string s, int a, int b, string &ans, unordered_set<string> &occured){
        if(occured.count(s)){
            return ;
        }

        occured.insert(s);
        ans = min(ans, s);

        string s1 = rotateRight(s, b);
        solve(s1, a, b, ans, occured);

        string s2 =  addA(s, a);
        solve(s2, a, b, ans, occured);
        
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans(100, '9');
        unordered_set<string> occured;
        solve(s, a, b, ans, occured);
        return ans;
    }
};