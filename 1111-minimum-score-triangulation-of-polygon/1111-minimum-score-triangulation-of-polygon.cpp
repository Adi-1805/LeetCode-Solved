class Solution {
    unordered_map<int, int> mp;
    int f(int start_index, int end_index, vector<int>& values){
        if(end_index - start_index < 2) return 0;
        if(end_index - start_index == 2) return values[start_index] * values[start_index + 1] * values[end_index];
                               
        // mapping the current vertices as visted
        int key = start_index*values.size() + end_index;
        if(!mp.count(key)){
            long long int minScore = INT_MAX;
            for(int k = start_index+1; k < end_index; k++){
                long long score = values[start_index]*values[k]*values[end_index] + f(start_index, k, values) + f(k, end_index, values);
                minScore = min(minScore, score);
            }
            mp[key] = minScore;
        }
        return mp[key];     
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return f(0, n-1, values);
    }
};