class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        string bin = "0";
        for(int i = 0; i < n-1; i++){
            string temp = "";
            for(int i = bin.size()-1; i >= 0; i--){
                if(bin[i] == '1') temp += '0';
                else temp += '1';
            }
            bin += "1";
            bin += temp;
        }
        return bin[k-1];
    }
};