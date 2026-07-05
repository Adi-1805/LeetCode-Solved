class Solution {
    const int MOD = 1e9 + 7;
    int m, n;
    vector<string> board;
    vector<vector<pair<int,int>>> dp;
    vector<vector<bool>> vis;

    pair<int,int> solve(int i, int j) {
        if(i >= m || j >= n || board[i][j] == 'X') return {-1, 0};
        if(board[i][j] == 'S') return {0, 1};
        if(vis[i][j]) return dp[i][j];
    
        vis[i][j] = true;
        auto [rightScr, rightWays] = solve(i, j + 1);
        auto [downScr, downWays] = solve(i + 1, j);
        auto [diagScr, diagWays] = solve(i + 1, j + 1);

        if(rightScr == -1 && downScr == -1 && diagScr == -1) return dp[i][j] = {-1, 0};
        int maxScr = max({rightScr, downScr, diagScr});
        long long ways = 0;

        if(rightScr == maxScr) ways += rightWays;
        if(downScr == maxScr) ways += downWays;
        if(diagScr == maxScr) ways += diagWays;
        ways %= MOD;

        if(board[i][j] == 'E') return dp[i][j] = {maxScr, (int)ways};
        return dp[i][j] = {maxScr + (board[i][j] - '0'), (int)ways};
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        board = b; m = board.size(); n = board[0].size();
        dp.assign(m, vector<pair<int,int>>(n));
        vis.assign(m, vector<bool>(n, false));

        auto [score, ways] = solve(0, 0);
        if (score == -1) return {0, 0};
        return {score, ways};
    }
};