class Solution {
    int get_sum(int n){
        int sum = 0;
        while(n){
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        int ans = num;
        while(log10(ans) >= 1){
            ans = get_sum(ans);
        }
        return ans;
    }
};