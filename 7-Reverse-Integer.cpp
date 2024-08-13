class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int dig = 0;
        if(x<0){
            x = abs(x);
            while(x>0){
                dig = x%10;
                ans =  ans*10 + dig;
                x/=10; 
            }
            if( ans<INT_MAX && ans>INT_MIN) return -1*ans; 
            return 0;
        }
        while(x>0){
            dig = x%10;
            ans =  ans*10 + dig;
            x/=10; 
        }
        if( ans<INT_MAX && ans>INT_MIN) return ans; 
        return 0;
    }
};