class Solution {
    vector<int> dp;
    bool f(int ind, vector<int> &arr){
        if(ind < 0 || ind >= arr.size() || arr[ind] < 0) return 0;
        if(arr[ind] == 0) return 1;
        if(dp[ind] != -1) return dp[ind];
        arr[ind] *= -1; // essential to prevent recursion loops
        return dp[ind] = ( f(ind-arr[ind], arr) || f(ind+arr[ind], arr) );
    }
public:
    bool canReach(vector<int>& arr, int start) {
        dp.resize(arr.size()+1, -1);
        return f(start, arr);
    }
};