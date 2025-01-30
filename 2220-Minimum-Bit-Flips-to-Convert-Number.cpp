class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num1 = start ^ goal;
        int num2 = start & goal & num1;
        bitset<32> b1(num1), b2(num2);
        return b1.count() + b2.count();

    }
};