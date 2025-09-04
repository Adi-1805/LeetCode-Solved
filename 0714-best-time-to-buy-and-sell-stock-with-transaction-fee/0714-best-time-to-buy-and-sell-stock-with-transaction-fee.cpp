class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<int> ahead(2, 0);
        int aheadNotBuy = 0, aheadBuy = 0;

        for(int ind = n-1; ind >= 0; ind--){
            // vector<int> curr(2, 0);
            int curBuy = max(-prices[ind] + aheadNotBuy, aheadBuy);
            int curNotBuy = max( -fee + prices[ind] + aheadBuy, aheadNotBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};