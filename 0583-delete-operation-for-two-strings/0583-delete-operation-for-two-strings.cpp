class Solution {
    int LCS(string &s1, string &s2){
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0);

        for(int ind1 = 1; ind1 <= n; ind1++){
            vector<int> curr(n+1, 0);
            for(int ind2 = 1; ind2 <= m; ind2++){
                if(s1[ind1-1] == s2[ind2-1]) curr[ind2] = 1 + prev[ind2-1];
                else curr[ind2] = max(prev[ind2], curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(); int m = word2.size();
        if(m > n) swap(word1, word2); // Assuming word1 to be the longer word
        int lcs = LCS(word1, word2);
        return (m - lcs) + (n - lcs); // No of deletions + No of insertions
    }
};