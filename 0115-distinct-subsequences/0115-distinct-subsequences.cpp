class Solution {
    int m, n;
    vector<vector<int>> dp;
    int solve(int ind1, int ind2, string s, string t){
        if(ind2 < 0) return 1; // if the second string exhausts, it means we found string2 in string1
        if(ind1 < 0) return 0; // if the first string exhausts, the recursion is over

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s[ind1] == t[ind2]) return dp[ind1][ind2] = solve(ind1-1, ind2-1, s, t) + solve(ind1-1, ind2, s, t);
        return dp[ind1][ind2] = solve(ind1-1, ind2, s, t);
    }
public:
    int numDistinct(string s, string t) {
        n = s.size(); m = t.size();
        dp.resize(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, t);
    }
};