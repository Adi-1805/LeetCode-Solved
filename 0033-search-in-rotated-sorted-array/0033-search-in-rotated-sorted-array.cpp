class Solution {
    int pivot(vector<int>& nums){
        int s = 0; int e = nums.size() -1;
        int mid = (e-s)/2 + s;
        while(s<e){
            if(nums[mid] >= nums[0]) s = mid +1;
            else e = mid;
            mid = (e-s)/2 + s;
        }
        return s;
    }
    int binarySearch(vector<int>& nums,int s, int e, int target){
        int mid = (e-s)/2 + s;
        while(s<=e){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                e = mid -1;
            }else{
                s = mid + 1;
            }
            mid = (e-s)/2 + s;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int piv = pivot(nums);
        if( target >= nums[piv] and target <= nums[nums.size()-1]){
            return binarySearch(nums,piv,nums.size()-1,target);
        }else{
            return binarySearch(nums,0,piv-1,target);
        }
    }
};