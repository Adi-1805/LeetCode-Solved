class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        int n = nums.size();

        // right[x] = how many times value x appears at indices >= current j
        unordered_map<long long, long long> right, left;

        for (int x : nums) right[x]++;

        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            // current index j can't be used as k anymore
            if (--right[nums[j]] == 0) right.erase(nums[j]);

            long long target = 2LL * nums[j];
            auto itL = left.find(target);
            auto itR = right.find(target);
            if (itL != left.end() && itR != right.end()) {
                ans = (ans + (itL->second * itR->second) % MOD) % MOD;
            }
            // now j becomes part of the left side for future indices
            left[nums[j]]++;
        }

        return static_cast<int>(ans);
    }
};
