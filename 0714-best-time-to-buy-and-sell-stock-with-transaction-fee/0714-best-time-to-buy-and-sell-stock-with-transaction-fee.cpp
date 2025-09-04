class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return f(0, 1, prices, fee, dp);

        for(int ind = n-1; ind >= 0; ind--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                long profit = 0;
                if(canBuy) profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                else profit = max( -fee + prices[ind] + dp[ind+1][1], dp[ind+1][0]);
                dp[ind][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};