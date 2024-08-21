class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end()); sort(s.begin(), s.end());
        for(int i = 0; i < s.size() and ans < g.size(); i++){
            if(s[i] >= g[ans]) ans++;  
        }
        return ans;
    }
};