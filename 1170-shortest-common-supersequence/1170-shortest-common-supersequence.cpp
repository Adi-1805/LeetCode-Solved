#include <string>
class Solution {
    string longestSupersqn(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // cout << dp[n][m] << endl;

        // backtrack
        string ans = "";
        for(int i = 0; i < (n + m - dp[n][m]); i++){
            ans += " ";
        }

        int i = n, j = m, index = (n + m - dp[n][m]) - 1;
        while(i > 0 and j > 0){
            if(s1[i-1] == s2[j-1]){
                ans[index] = s1[i-1]; index--; i--; j--;
            } 
            else if(dp[i-1][j] > dp[i][j-1]){
                ans[index] = s1[i-1]; index--; i--;
            } 
            else{
                ans[index] = s2[j-1]; index--; j--;
            }
        }

        // Adding the remaining characters of whichever string (str1 or str2) is left into the supersqn
        while(i > 0) {
            ans[index] = s1[i-1]; index--; i--;
        }
        while(j > 0) {
            ans[index] = s2[j-1]; index--; j--;
        }

        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        return longestSupersqn(str1, str2);
    }
};