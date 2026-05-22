class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long int nn = (n < 0) ? -1LL*n : n;
        while(nn > 0){
            if(nn&1) ans = (ans*x);
            x = (x*x);
            nn >>= 1;
        }
        return (n >= 0) ? ans : (1.0/ans);
    }
};