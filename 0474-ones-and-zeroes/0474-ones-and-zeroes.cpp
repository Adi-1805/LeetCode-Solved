class Solution {
    vector<vector<vector<int>>> dp;
    int f(int ind, int zerocnt, int onecnt, vector<string> &strs, int m, int n){
        if(ind == strs.size()) return 0;
        if(dp[ind][zerocnt][onecnt] != -1) return dp[ind][zerocnt][onecnt];
      
        int skip = f(ind+1, zerocnt, onecnt, strs, m, n), pick = 0;
        bitset<100> bits(strs[ind]); // bitset size = 100 because that's the max string length
        if(onecnt + bits.count() <= n and zerocnt + (strs[ind].size() - bits.count()) <= m){
            pick = 1 + f(ind+1, zerocnt + (strs[ind].size() - bits.count()), onecnt + bits.count(), strs, m, n);
        }

        return dp[ind][zerocnt][onecnt] = max(skip, pick);

    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return f(0, 0, 0, strs, m, n);
    }
};