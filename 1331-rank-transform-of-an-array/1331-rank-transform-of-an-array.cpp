class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        
        map<int, vector<int>> mp; // stores: value -> {index of occurence}
        for(int i = 0; i < arr.size(); i++) mp[arr[i]].push_back(i); 

        // calculate rank like this and node using the iterator as commented cuz the iterator multiplies an additional O(n)
        int rank = 1;
        for(map<int, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++){
            int val = it->first;
            vector<int> pos = it->second;
            // int rank = distance(mp.begin(), it);
            for(int ind: pos){
                arr[ind] = rank;
            }
            rank++; // increment after processing all the indexes
        }
        return arr;
    }
};