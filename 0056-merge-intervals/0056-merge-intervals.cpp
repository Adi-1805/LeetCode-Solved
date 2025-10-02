class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        for(int i = 0; i < intervals.size(); i++){
            vector<int> currInt = intervals[i];
            if(result.empty() or result.back()[1] < currInt[0]){
                result.push_back(currInt);
            }else{
                result.back()[1] = max(result.back()[1], currInt[1]);
            }
        }

        return result;
    }
};