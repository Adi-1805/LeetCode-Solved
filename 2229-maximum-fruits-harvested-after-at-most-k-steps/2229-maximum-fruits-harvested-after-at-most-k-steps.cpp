class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos, amt, prefix(n+1, 0);
        for(int i = 0; i < n; ++i){
            pos.push_back(fruits[i][0]);
            amt.push_back(fruits[i][1]);
        }
        for(int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + amt[i];

        int ans = 0;
        for(int i = 0; i < n; ++i){
            int l = pos[i];
            int maxR = startPos + (k - 2*max(0, startPos-l));
            auto it = upper_bound(pos.begin(), pos.end(), maxR);
            int j = it - pos.begin(); 
            ans = max(ans, prefix[j] - prefix[i]);
        }
        for(int i = 0; i < n; ++i){
            int r = pos[i];
            int minL = startPos - (k - 2*max(0, r-startPos));
            auto it = lower_bound(pos.begin(), pos.end(), minL);
            int j = it - pos.begin(); 
            if (j <= i) ans = max(ans, prefix[i+1] - prefix[j]);
        }

        return ans;
    }
};