class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        
        int pivot = -1; // last occurence where the curr element is smaller than the next
        int greaterThanPivot = 0; // first occurence where the element, from the back of the permut, is greater than pivot 
        for(int i = 0; i < n-1; i++){
            if(nums[i] < nums[i+1]){
                pivot = i; 
            }
        }

        // Early exit cuz if pivot is not updated then last index is pivot which implies the vector is in descending order i.e., the last permutation
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int j = n-1; j >= 1; j--){
            // if we put equal sign here (>=) it will fail for dupilcates because that'll cause pivot to be == greaterThanPivot hence generating same permut
            if(nums[j] > nums[pivot]){
                greaterThanPivot = j; break;
            }
        }

        swap(nums[pivot], nums[greaterThanPivot]);
        reverse(nums.begin() + pivot + 1, nums.end()); // reverse the suffix to get the right order
    }
};