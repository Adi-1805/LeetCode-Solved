class Solution {
public:
    long long sumAndMultiply(int n) {
        int place = 1;
        long long new_int = 0;
        long long sum = 0;
        while(n>0){ 
            int digit = n%10;
            if(digit != 0){
                new_int += (place*digit);
                sum += digit;
                place *= 10;
            }
            n /= 10;
        }
        return 1LL*sum*new_int;
    }
};