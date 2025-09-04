class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0);
        // return f(0, 1, prices, fee, dp);

        for(int ind = n-1; ind >= 0; ind--){
            vector<int> curr(2, 0);
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                long profit = 0;
                if(canBuy) profit = max(-prices[ind] + ahead[0], ahead[1]);
                else profit = max( -fee + prices[ind] + ahead[1], ahead[0]);
                curr[canBuy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};