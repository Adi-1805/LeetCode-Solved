class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = LLONG_MAX, maxi = LLONG_MIN;
        for(int val: nums){
            if(mini > val) mini = val;
            if(maxi < val) maxi = val;
        }
        return 1LL*k*(maxi-mini);
    }
};