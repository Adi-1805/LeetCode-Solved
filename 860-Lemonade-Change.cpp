class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num5 = 0, num10 = 0;
        for(int val: bills){
            if(val == 5) num5++;
            else if(val == 10){
                if (num5 > 0) {
                    num5--; num10++;
                }
                else return false;
            } 
            else{
                if(num10 > 0 and num5 > 0){
                    num10--; num5--; 
                } 
                else if(num5 >2) {
                    num5 -= 3; 
                }
                else return false;
            }
        }
        return true;
    }
};