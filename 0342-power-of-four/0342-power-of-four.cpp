class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;
        return (n & (n-1)) == 0 && (n & 0b01010101010101010101010101010101);
    }
};