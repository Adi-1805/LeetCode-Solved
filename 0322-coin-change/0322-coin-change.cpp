class Solution {
    vector<vector<int>> dp;
    int solve(int ind, int amt, vector<int> &coins){
        if(ind == 0){
            if(amt % coins[0] == 0) return amt/coins[0];
            else return 1e9;
        }
        if(dp[ind][amt] != -1) return dp[ind][amt];
        
        int not_take = solve(ind-1, amt, coins);
        int take = 1e9;
        // since a coin of one denomination can be chosen more than once, we will no change the index when we take
        if(coins[ind] <= amt) take = 1 + solve(ind, amt - coins[ind], coins);
        return dp[ind][amt] = min(not_take, take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n, vector<int>(amount+1, -1));
        // bool ans = 1;
        // for(int i = 0; i < n; i++){
        //     if(amount%coins[i]) ans = 0;
        //     else{
        //         ans = 1; break;
        //     }
        // }
        // if(ans == 0) return -1;
        int ans = solve(n-1, amount, coins);
        return (ans == 1e9) ? -1 : ans;
    }
};