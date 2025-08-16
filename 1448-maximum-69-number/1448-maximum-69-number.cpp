class Solution {
public:
    int maximum69Number (int num) {
        int temp = num; int decimal = 10000;
        while(decimal){
            int digit = (temp/decimal);
            if(digit == 6){
                num = num - (6*decimal) + (9*decimal); break;
            }
            temp = temp - (digit*decimal);
            decimal /= 10;
        }
        return num;
    }
};