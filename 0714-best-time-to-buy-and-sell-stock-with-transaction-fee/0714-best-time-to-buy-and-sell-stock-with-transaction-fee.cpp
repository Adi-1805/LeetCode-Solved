class Solution {
    int f(int ind, bool canBuy, vector<int> &prices, int fee, vector<vector<int>> &dp){
        if(ind == prices.size()) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        long profit = 0;
        if(canBuy) profit = max(-prices[ind] + f(ind+1, 0, prices, fee, dp), f(ind+1, 1, prices, fee, dp));
        else profit = max( -fee + prices[ind] + f(ind+1, 1, prices, fee, dp), f(ind+1, 0, prices, fee, dp));
        return dp[ind][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);
    }
};