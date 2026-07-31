class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> freq;
        for(char ch: word) freq[ch]++;
        vector<pair<char, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](const auto &a, const auto &b){
            return a.second > b.second;
        });
        int pushes = 0;
        for(int i = 0; i < v.size(); i++){
            pushes += v[i].second*(i/8 + 1);
        }  
        return pushes;
    }
};