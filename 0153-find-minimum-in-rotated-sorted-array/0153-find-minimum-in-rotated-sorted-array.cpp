class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int minimum = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= nums[low]){
                // left sorted
                minimum = min(minimum, nums[low]);
                low = mid + 1;
            }else{
                // right sorted
                minimum = min(minimum, nums[mid]);
                high = mid - 1;
            }
        }
        return minimum;
    }
};