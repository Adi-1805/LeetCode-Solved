#define ull unsigned long long int
class Solution {
    // Here tabulation will give TLE but the memoization won't because during (recursion+) memoization we do not calculate every state but in tabulation we do. Hence this is one of those situations where calculating all the states in a tabulation gives a TLE.
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ull>> dp(n, vector<ull>(amount+1, 0));
        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0]) dp[0][amt] = 0;
            else dp[0][amt] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            for(int amt = 0; amt <= amount; amt++){
                ull not_take = dp[ind-1][amt], take = 0;
                if(coins[ind] <= amt) take = dp[ind][amt - coins[ind]];
                dp[ind][amt] = not_take + take;
            }
        }
        return dp[n-1][amount];
    }
};