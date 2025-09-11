class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSoFar = prices[0];
        int maxprofit = 0;
        for(int i = 1; i < n; i++){
            if(minSoFar > prices[i]){
                minSoFar = prices[i];
            }
            maxprofit = max(maxprofit, prices[i] - minSoFar);
        }
        return maxprofit;
    }
};