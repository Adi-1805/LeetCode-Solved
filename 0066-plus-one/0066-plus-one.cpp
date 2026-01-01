class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i = n-1; i >= 0; i--){
            int digit = digits[i];
            if(digit + carry >= 10){
                digits[i] = (digit + carry)%10;
                carry = 1;
            }else{
                digits[i] = (digit+carry)%10;
                carry = 0;
            }
        }
        if(carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};