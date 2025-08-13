class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;
        return  __builtin_popcount(n) == 1 && (n & 0b01010101010101010101010101010101);
    }
};