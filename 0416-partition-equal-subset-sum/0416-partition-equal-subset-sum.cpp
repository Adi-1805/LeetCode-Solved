class Solution {
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool> prev(sum+1, 0);
        prev[0] = 1;
        if(arr[0] <= sum) prev[arr[0]] = 1;
 
        for(int ind = 1; ind < n; ind++){
            vector<bool> curr(sum+1, 0);
            curr[0] = 1;
            for(int target = 1; target <= sum; target++){
                bool notpick = prev[target];
                bool pick = 0;
                if(target >= arr[ind]) pick = prev[target - arr[ind]];
                curr[target] = pick || notpick;
            }
            prev = curr;
        }
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        long long int total = accumulate(nums.begin(), nums.end(), 0);
        if(total&1) return 0;
        return isSubsetSum(nums, total/2);
    }
};