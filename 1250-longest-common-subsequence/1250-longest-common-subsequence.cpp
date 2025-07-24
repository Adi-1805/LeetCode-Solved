class Solution {
    vector<vector<int>> dp;
    int solve(int ind1, int ind2, string &s1, string &s2){
        if(ind1 < 0 or ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = 1 + solve(ind1-1, ind2-1, s1, s2);

        return dp[ind1][ind2] = max( solve(ind1-1, ind2, s1, s2), solve(ind1, ind2-1, s1, s2) );
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.resize(n, vector<int>(m, -1));
        return solve(n-1, m-1, text1, text2);
    }
};