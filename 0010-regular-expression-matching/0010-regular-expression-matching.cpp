class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));
        dp[0][0] = 1;
        for(int j = 2; j <= n; j++) if(p[j-1] == '*') dp[0][j] = dp[0][j-2];

        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                if(p[j-1]=='.' or s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } 
                else if(p[j-1] == '*') {
                    if(j >= 2){
                        dp[i][j] = dp[i][j-2]; // case where "x*" is considered empty string
                        if(p[j-2] == '.' or s[i-1] == p[j-2] ){
                            dp[i][j] = dp[i-1][j] | dp[i][j];
                        }
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m][n];
    }
};