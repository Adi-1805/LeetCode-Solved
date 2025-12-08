class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target) return true;

            if(arr[low] == arr[mid] and arr[mid] == arr[high]){
                // shrink the array on both sides by 1
                low = low +1; high = high -1;
            }
            else if(arr[low] <= arr[mid]){
                // left sorted
                if(arr[low] <= target and target < arr[mid]) high = mid-1;
                else low = mid + 1;
            }else{
                //right sorted
                if(arr[mid] < target and target <= arr[high]) low = mid+1;
                else high = mid -1;
            }
        }
        return false;
    }
};