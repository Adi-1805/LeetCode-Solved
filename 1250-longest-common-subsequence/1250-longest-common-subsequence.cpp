class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1, 0);

        for(int ind1 = 1; ind1 <= n; ind1++){
            vector<int> cur(m+1, 0);
            for(int ind2 = 1; ind2 <= m; ind2++){
                if(text1[ind1-1] == text2[ind2-1]) cur[ind2] = 1 + prev[ind2-1];
                else cur[ind2] = max( prev[ind2], cur[ind2-1] );
            }
            prev = cur;
        }

        return prev[m];
    }
};