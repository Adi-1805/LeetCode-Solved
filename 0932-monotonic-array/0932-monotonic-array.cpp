class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;

        bool flag1 = 1, flag2 = 1; 
        for(int i = 1; i < n; i++){
            if(arr[i-1] > arr[i]){
                flag1 = 0;
            }
            else if(arr[i] > arr[i-1]){
                flag2 = 0;
            }
            if(!flag1 and !flag2) break;
        }

        if(flag1 or flag2) return 1;
        return 0;
    }
};