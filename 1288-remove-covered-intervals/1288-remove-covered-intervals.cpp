class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int overlaps = 0, last = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[last][0] == intervals[i][0] and intervals[last][1] < intervals[i][1]){
                // when intervals overlap and new covers the last interval
                overlaps++;
                last = i;
            }else if(intervals[last][1] >= intervals[i][1]){
                // when intervals overlap and last covers the new interval
                overlaps++;
            }else{
                last = i;
            }
        }
        return intervals.size() - overlaps;
    }
};