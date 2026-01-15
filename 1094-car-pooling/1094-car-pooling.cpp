class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        int n = trips.size();
        for(int i = 0; i < n; i++){
            vector<int> trip = trips[i];
            mp[trip[1]] += trip[0];
            mp[trip[2]] -= trip[0];
        }

        int cur_passenger_count = 0;
        for(auto it: mp){
            cur_passenger_count += it.second;
            if(cur_passenger_count > capacity) return false;
        }
        return true;
    }
};