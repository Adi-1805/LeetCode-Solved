class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0, temp = n;
        while(temp){
            ans = ans ^ temp;
            temp >>= 1;
        }
        return ans;
    }
};