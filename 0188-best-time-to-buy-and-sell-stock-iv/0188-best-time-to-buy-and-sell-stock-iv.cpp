class Solution {
    vector<vector<vector<int>>> dp;
    int f(int ind, vector<int>& prices, bool canBuy, int limit, int k){
        if(ind == prices.size()) return 0;
        if(limit == k) return 0;
        if(dp[ind][canBuy][limit] != -1) return dp[ind][canBuy][limit];

        long profit = 0;
        if(canBuy){
            profit = max(-prices[ind] + f(ind+1, prices, 0, limit, k),
                            f(ind+1, prices, 1, limit, k));
        }else{
            profit = max(prices[ind] + f(ind+1, prices, 1, limit+1, k),
                            f(ind+1, prices, 0, limit, k));
        }

        return dp[ind][canBuy][limit] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<vector<int>>(2, vector<int>(k, -1)));
        return f(0, prices, 1, 0, k);
    }
};