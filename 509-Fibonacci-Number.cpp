class Solution {
public:
    int fib(int n) {
        int first = 0, second = 1; int ans = 0;
        if( n==0 || n==1 ) return n;
        for(int i = 1; i<n; i++){
            ans = first + second;
            first = second;
            second = ans;
        }
        return ans;
    }
};