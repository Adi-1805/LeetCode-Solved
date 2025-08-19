class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) {
        int n = arr.size();
        long long zeroCnt = 0, result = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                zeroCnt++;
            }
            else{
                result += (zeroCnt)*(zeroCnt+1)/2;
                zeroCnt = 0;
            }
        }
        if(zeroCnt) result += (zeroCnt)*(zeroCnt+1)/2;
        return result;
    }
};