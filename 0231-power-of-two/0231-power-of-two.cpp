class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> bits(n);
        return (bits.count() == 1 and n != INT_MIN);
    }
};