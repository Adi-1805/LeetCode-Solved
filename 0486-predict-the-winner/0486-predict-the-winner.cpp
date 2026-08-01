class Solution {
    using ll = long long;
    vector<int> arr; vector<vector<int>> dp;
    ll solve(int l, int r){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        ll take_l = arr[l] + min(solve(l+2, r), solve(l+1, r-1));
        ll take_r = arr[r] + min(solve(l+1, r-1), solve(l, r-2));
        return dp[l][r] = max(take_l, take_r);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        arr = nums; dp.resize(n, vector<int>(n, -1));
        ll total = accumulate(nums.begin(), nums.end(), 0LL);
        ll p1 = solve(0, n-1), p2 = total - p1;
        return p1 >= p2;
    }
};