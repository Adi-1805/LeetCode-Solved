class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // edge cases
        if(n == 1) return 0;
        else if(nums[0] > nums[1]) return 0;
        else if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1, high = n-2;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]) return mid;
            if(nums[mid] < nums[mid-1]){
                // slope is like this "\"
                high = mid-1;
            }else{
                // slope is like this "/" or "--"
                low = mid+1;
            }
        }
        return -1;
    }
};