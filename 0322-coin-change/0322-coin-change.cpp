class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int amt = 0; amt <= amount; amt++){
            if(amt%coins[0]) dp[0][amt] = 1e9;
            else dp[0][amt] = amt/coins[0];
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int amt = 0; amt <= amount; amt++){
                int not_take = dp[ind-1][amt];
                int take = 1e9;
                // since a coin of one denomination can be chosen more than once, we will no change the index when we take
                if(coins[ind] <= amt) take = 1 + dp[ind][amt-coins[ind]];
                dp[ind][amt] = min(not_take, take);
            }
        }

        int ans = dp[n-1][amount];
        return (ans == 1e9) ? -1 : ans;
    }
};