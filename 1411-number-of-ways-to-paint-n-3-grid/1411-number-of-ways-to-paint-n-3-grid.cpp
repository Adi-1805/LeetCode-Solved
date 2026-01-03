class Solution {
    long long M = 1000000007;
public:
    int numOfWays(int n) {
        if(n == 1) return 12;
        long long x = 6, y = 6;
        int result = 0;
        for(int i = 2; i <=n; i++){
            long long newX = ((2*x)%M + (2*y)%M)%M;
            long long newY = ((2*x)%M + (3*y)%M)%M;
            x = newX; y = newY;
            result = (newX + newY)%M;
        }
        return result;
    }
};