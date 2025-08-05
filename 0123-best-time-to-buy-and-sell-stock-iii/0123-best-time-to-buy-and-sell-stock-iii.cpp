class Solution {
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& arr, int ind, bool buy, int limit){
        if(limit == 0) return 0;
        if(ind == arr.size()) return 0;
        if(dp[ind][buy][limit] != -1) return dp[ind][buy][limit];

        int profit = 0;
        if(buy){
            profit = max( -arr[ind] + solve(arr, ind+1, 0, limit), 0 + solve(arr, ind+1, 1, limit) );
        } else {
            profit = max( arr[ind] + solve(arr, ind+1, 1, limit-1), 0 + solve(arr, ind+1, 0, limit) );
        }
        return dp[ind][buy][limit] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 1, 2);
    }
};