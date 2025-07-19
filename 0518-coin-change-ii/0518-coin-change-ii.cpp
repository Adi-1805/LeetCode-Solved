class Solution {
    int solve(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amt % coins[ind] == 0) return 1;
            else return 0;
        }
        if(dp[ind][amt] != -1) return dp[ind][amt];

        int not_take = solve(ind-1, amt, coins, dp), take = 0;
        if(coins[ind] <= amt) take = solve(ind, amt - coins[ind], coins, dp);
        return dp[ind][amt] = not_take + take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};