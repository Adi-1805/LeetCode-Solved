class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int n = digits.size();
        int carry = 1;
        for(int i = n-1; i >= 0; i--){
            int digit = digits[i];
            // cout << digit << " " << carry << endl;
            if(digit + carry >= 10){
                result.push_back((digit + carry)%10);
                carry = 1;
            }else{
                result.push_back(digit+carry);
                carry = 0;
            }
        }
        if(carry == 1) result.push_back(carry);
        reverse(result.begin(),result.end());
        return result;
    }
};