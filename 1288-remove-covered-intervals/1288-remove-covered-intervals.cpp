class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int overlaps = 0, last = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[last][0] == intervals[i][0] and intervals[last][1] < intervals[i][1]){
                cout << "here" << " ";
                overlaps++;
                last = i;
            }else if(intervals[last][1] >= intervals[i][1]){
                overlaps++;
            }else{
                last = i;
            }
            cout << overlaps << " : " << last << endl;
        }
        return intervals.size() - overlaps;
    }
};