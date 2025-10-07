class Solution {
    int countReversePairs = 0;
    void merge(int low, int high, int mid, vector<int> &nums){
        int m = mid - low + 1, n = high - mid;

        // pushing elements in a sorted manner in a temporary vector
        vector<int> v;
        int i = low, j = mid+1;
        while(i <= mid and j <= high){
            if(nums[i] <= nums[j]) v.push_back(nums[i++]);
            else v.push_back(nums[j++]);
        }
        while(i <= mid) v.push_back(nums[i++]);
        while(j <= high) v.push_back(nums[j++]);
        
        // copying the correct order in the original array
        for(int i = 0; i < v.size(); i++){
            nums[i+low] = v[i]; // v[0] goes to arr[low]
        }
    }
    void mergeSort(int low, int high, vector<int> &nums){
        if(low >= high) return ;
        int mid = (low+high)/2;
        mergeSort(low, mid, nums);
        mergeSort(mid+1, high, nums);

        // counting before merging the two arrays such that reverse pairs are counted for each element before it is merged
        int i = low, j = mid+1;
        while(i <= mid and j <= high){
            if(nums[i] > (long long)2*nums[j]){
                countReversePairs += (mid - i + 1);
                j++;
            }else{
                i++;
            }
        }

        merge(low, high, mid, nums);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n-1, nums);
        return countReversePairs;
    }
};