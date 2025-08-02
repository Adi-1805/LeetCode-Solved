class Solution {
    vector<vector<int>> dp;
    bool f(int i, int j, string& s, string& p){
        if(i < 0 and j < 0) return true;
        if(j < 0 and i >= 0) return false;
        if(i < 0 and j >= 0){
            for(int k = j; k >= 0; k--){
                if(p[k] != '*') return false;
            } 
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = f(i-1, j-1, s, p);
        else if(p[j] == '*') return dp[i][j] = f(i-1, j, s, p) || f(i, j-1, s, p);
        

        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.resize(n, vector<int>(m, -1));
        return f(n-1, m-1, s, p);
    }
};