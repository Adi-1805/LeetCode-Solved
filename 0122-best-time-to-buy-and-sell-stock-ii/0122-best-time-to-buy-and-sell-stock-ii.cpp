class Solution {
    int n;
    vector<vector<int>> dp;
    long f(vector<int>& arr ,int ind, bool buy){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        long profit = -1e9;
        if(buy){
            profit = max( -arr[ind] + f(arr, ind+1, 0), 0 + f(arr, ind+1, 1));
        }else{
            profit = max( arr[ind] + f(arr, ind+1, 1), 0 + f(arr, ind+1, 0));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        return f(prices, 0, 1);
    }
};