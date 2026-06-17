class Solution {
public:
    vector<int> grayCode(int n) {
        int bitsize = 1<<n;
        int gray_val = 0;
        vector<int> result;
        for(int i = 0; i < bitsize; i++){
            gray_val = i^(i>>1);
            result.push_back(gray_val);
        }
        return result;
    }
};