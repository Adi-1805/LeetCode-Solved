class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = (INT_MIN), area = 0; 
        double longestDiagonal = -1.0;
        for(auto& r: dimensions){
            int x = r[0], y = r[1];
            if(longestDiagonal < sqrt(x*1.0*x + y*1.0*y)){
                maxArea = x*y;
                longestDiagonal = sqrt(x*1.0*x*1.0 + y*1.0*y*1.0);
            }else if(longestDiagonal == sqrt(x*1.0*x + y*1.0*y)){
                maxArea = max(maxArea, x*y);
            }
        }
        return maxArea;
    }
};