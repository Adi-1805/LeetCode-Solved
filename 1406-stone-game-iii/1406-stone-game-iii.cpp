class Solution {
    int solve(int ind, vector<int> &arr, vector<int> &dp){
        int n = arr.size();
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int result = max(INT_MIN, arr[ind] - solve(ind+1, arr, dp));
        if(ind+1 < n) result = max(result, arr[ind] + arr[ind+1] - solve(ind+2, arr, dp));
        if(ind+2 < n) result = max(result, arr[ind] + arr[ind+1] + arr[ind+2] - solve(ind+3, arr, dp));
        return dp[ind] = result;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), -1);
        int diff = solve(0, stoneValue, dp);
        return (diff >= 0) ? ( diff != 0 ? "Alice" : "Tie") : "Bob";
    }
};