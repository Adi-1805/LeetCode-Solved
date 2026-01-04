class Solution {
    long long getDivisorSum(int num){
        long long sum = 1 + num, count = 2; // pre-counting 1 and num itself as dividors
        for(long long i = 2; i*i <= num*1LL; i++){
            if(num%i == 0){
                if(i == num/i){
                    count += 1; sum += i;
                }else{
                    count += 2; 
                    sum += (i + (num/i));
                }
            }
        }
        return (count == 4) ? sum : 0; 
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int required_sum = 0;
        for(int i = 0; i < n; i++){
            required_sum += getDivisorSum(nums[i]);
        }
        return required_sum;
    }
};