class Solution {
    using ll = long long;
    vector<vector<vector<int>>> dp;

    ll solve(int ind, int M, int alice, vector<int>& arr) {
        if (ind >= arr.size()) return 0;
        if (dp[ind][M][alice] != -1) return dp[ind][M][alice];

        if (alice) {
            ll cur_score = 0;
            ll taken = 0;
            // Alice can take X = 1 ... 2*M piles
            for (int X = 1; X <= 2 * M && ind + X <= arr.size(); X++) {
                // Add the X-th pile to the total Alice takes
                taken += arr[ind + X - 1];
                ll score = taken + solve(ind + X, max(M, X), 0, arr);
                // Alice wants to maximize her stones
                cur_score = max(cur_score, score);
            }
            return dp[ind][M][alice] = cur_score;
        }
        else{
            ll cur_score = LLONG_MAX;
            // Bob can take X = 1 ... 2*M piles
            for (int X = 1; X <= 2 * M && ind + X <= arr.size(); X++) {
                // Bob's stones are NOT added to Alice's score. We only care about how many stones Alice can get after Bob makes this move.
                ll score = solve(ind + X, max(M, X), 1, arr);
                // Bob wants to minimize Alice's final score
                cur_score = min(cur_score, score);
            }
            return dp[ind][M][alice] = cur_score;
        }
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return solve(0, 1, 1, piles);
    }
};