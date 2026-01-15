class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> hash(1001, 0);
        int n = trips.size();
        for(int i = 0; i < n; i++){
            vector<int> trip = trips[i];
            for(int i = trip[1]; i < trip[2]; i++){
                hash[i] += trip[0];
            }
        }
        
        if( capacity >= *max_element(hash.begin(), hash.end()) ) return true;
        return false;
    }
};