class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        bool inc = (arr[1] >= arr[0]) ? 1 : 0; 
        if(inc){
            for(int i = 1; i < n; i++){
                if(arr[i-1] > arr[i]) return 0;
            }
            return 1;
        }
        else{
            for(int i = 1; i < n; i++){
                if(arr[i] > arr[i-1]) return 0;
            }
            return 1;
        }
        return 0;
    }
};