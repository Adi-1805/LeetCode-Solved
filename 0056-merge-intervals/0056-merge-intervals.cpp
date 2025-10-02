class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            vector<int> currInt = intervals[i];
            vector<int> prevInt = result.back();
            if(prevInt[1] >= currInt[0]){
                vector<int> back = result.back();
                result.pop_back();
                if(currInt[1] <= prevInt[1]) result.push_back(back);
                else result.push_back({ back[0], intervals[i][1]});
            }else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};