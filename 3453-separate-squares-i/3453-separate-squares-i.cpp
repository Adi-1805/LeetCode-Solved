class Solution {
    void getArea(const double line, vector<vector<int>> &sqrs, double &above, double &below){
        for(auto &sq: sqrs){
            double y = sq[1], l = sq[2];
            double top_y = y+l;
            if(line > top_y) below += (l*l);
            else if(line < y) above += (l*l);
            else{
                above += l*(top_y-line);
                below += l*(line-y);
            }
        }
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double max_y = 0.0, min_y = 0.0;
        for(auto &square: squares){
            int y = square[1], l = square[2];
            max_y = max(max_y, double(y+l));
            min_y = min(min_y, double(y));
        }
        double low = min_y, high = max_y;
        while((high-low) > 1e-5){
            double mid = (low) + (high-low)/2.0;
            double area_above = 0.0, area_below = 0.0;
            getArea(mid, squares, area_above, area_below);
            if(area_above < area_below || area_above == area_below) high = mid;
            else low = mid;
        }
        return low;
    }
};