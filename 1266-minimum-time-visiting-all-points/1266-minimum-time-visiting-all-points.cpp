class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 0;
        int seconds = 0; 
        vector<int> start = points[0];
        for(int i = 1; i < n; i++){
            vector<int> next = points[i];
            int vert_diff = abs(start[1]-next[1]);
            int horz_diff = abs(start[0]-next[0]);
            if(vert_diff == horz_diff) seconds += (vert_diff);
            else seconds += max(vert_diff, horz_diff);
            start = points[i];
        }
        return seconds;
    }
};