class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(int i = 0; i < edges.size(); i++){
            for(int j =  0; j < 2; j++){
                mp[edges[i][j]]++;
            }
        }
        int ans = 0; int mxfreq = INT_MIN;
        for(auto it: mp){
            if(it.second > mxfreq){
                mxfreq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};