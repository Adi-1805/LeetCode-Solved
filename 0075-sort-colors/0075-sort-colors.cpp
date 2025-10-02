class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* Dutch Flag Algorithm:
            There are gonna be three pointers, low, mig and high, where we will ensure that everything between low and (mid-1)  is sorted, everything between mid to high is unsorted and everything after high is sorted. 
            At every point we're trying to achieve:
            [0, low-1] will contain 0s;
            [low, mid-1] will contain 1s;
            [mid, high] will be unsorted;
            [high+1, n-1] will contain 2s;

        */
        int n = nums.size();
        int left = 0, mid = 0, right = n-1;
        while(mid <= right){
            if(nums[mid] == 0){
                swap(nums[mid], nums[left]);
                mid++, left++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};