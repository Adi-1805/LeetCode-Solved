class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        // boundary cases
        if(n == 1) return nums[0];
        else if(nums[0] != nums[1]) return nums[0];
        else if(nums[n-1] != nums[n-2]) return nums[n-1];
        
        int low = 1, high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]) return nums[mid];
            if(nums[mid] == nums[mid-1]){
                if( (mid - 1)&1 ) high = mid-1;
                else low = mid+1;
            }else if(nums[mid] == nums[mid+1]){
                if( mid&1 ) high = mid-1;
                else low = mid+1; 
            }
        }
        return nums[low];
    }
};