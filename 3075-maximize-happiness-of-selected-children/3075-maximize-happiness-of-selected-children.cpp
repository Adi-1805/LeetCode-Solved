class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ind = 0, sum = 0;
        for(int d = 0; d < k; d++){
            int cur_val = happiness[ind] - d;
            if(cur_val >= 0){
                sum += cur_val;
            }
            ind++;
        }
        return sum;
    }
};