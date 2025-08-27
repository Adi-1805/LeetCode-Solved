class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0, area = 0;
        double longestDiagonal = -1.0;
        for(auto& r: dimensions){
            int x = r[0], y = r[1];
            area = x*y;
            if( longestDiagonal < (x*1.0*x + y*1.0*y) || (longestDiagonal == x*1.0*x + y*1.0*y and area > maxArea) ){
                maxArea = area;
                longestDiagonal = (x*1.0*x + y*1.0*y);
            }
        }
        return maxArea;
    }
};