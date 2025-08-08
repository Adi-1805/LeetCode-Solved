vector<vector<int>> arr = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
vector<vector<double>> dp;

class Solution {
public:
    double solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (dp[a][b] != -1.0) return dp[a][b];

        double result = 0.0;
        for (int i = 0; i < 4; i++) {
            result += solve(max(a - arr[i][0], 0), max(b - arr[i][1], 0));
        }
        return dp[a][b] = 0.25 * result;
    }

    double soupServings(int n) {
        if (n > 5000) return 1.0; // optimization
        dp.assign(n + 1, vector<double>(n + 1, -1.0));
        return solve(n, n);
    }
};