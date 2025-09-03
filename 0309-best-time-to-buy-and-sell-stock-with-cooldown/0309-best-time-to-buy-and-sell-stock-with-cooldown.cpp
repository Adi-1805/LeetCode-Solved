class Solution {
    vector<vector<int>> dp;
    int f(int ind, vector<int>& prices, bool canBuy){
        if(ind >= prices.size()) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        long profit = 0;
        if(canBuy){
            profit = max(-prices[ind] + f(ind+1, prices, 0),
                            f(ind+1, prices, 1));
        }else{
            profit = max(prices[ind] + f(ind+2, prices, 1),
                            f(ind+1, prices, 0));
        }

        return dp[ind][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        return f(0, prices, 1);
    }
};