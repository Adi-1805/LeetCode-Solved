class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int, int>> items;
        for (int i = 0; i < n; i++) {
            int units_per_box = boxTypes[i][1];
            items.push_back({units_per_box, i});
        }
        sort(items.rbegin(), items.rend());

        int max_units = 0;
        int cap = truckSize;

        for(auto &it : items){
            int i = it.second, u_p_b = it.first;
            int boxes = boxTypes[i][0], units = boxTypes[i][1]*boxes;
            if(cap >= boxes){
                max_units += units; cap -= boxes;
            }else{
                max_units += u_p_b*cap; break;
            }
        }
        return max_units;
    }
};