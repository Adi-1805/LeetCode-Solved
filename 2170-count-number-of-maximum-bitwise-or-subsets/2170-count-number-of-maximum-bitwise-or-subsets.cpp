class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int maxOr = nums[0];
        for(int i = 1; i < n; i++){
            maxOr |= nums[i];
        }
        sort(nums.begin(), nums.end());
    
        int total = 1 << n;
        int cnt = 0;

        for (int i = 0; i < total; i++) {
            int curOr = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    curOr |= nums[j];
                }
            }
            
            if(curOr == maxOr) cnt++;
        }
        return cnt;
    }
};