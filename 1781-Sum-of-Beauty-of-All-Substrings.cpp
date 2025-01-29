class Solution {
public:
    int beautySum(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for (auto i : mp) {
                    maxi = max(maxi, i.second);
                    mini = min(mini, i.second);
                }
                result += (maxi - mini);
            }
        }
        return result;
    }
};