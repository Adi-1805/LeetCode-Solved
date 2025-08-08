class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return f(prices, 0, 1);

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy < 2; buy++){
                long profit = -1e9;
                if(buy){
                    profit = max( -arr[ind] + dp[ind+1][0] , 0 + dp[ind+1][1] );
                }else{
                    profit = max( arr[ind] + dp[ind+1][1] , 0 + dp[ind+1][0] );
                }
                dp[ind][buy] = profit; 
            }
        }

        return dp[0][1];
    }
};