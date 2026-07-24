class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int bits = floor(log2(n))+1;
        return pow(2, bits);
    }
};