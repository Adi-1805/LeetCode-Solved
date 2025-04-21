class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long int> pfsum(n+1,0);
        // int net_dif = 0;
        for(int i = 1; i < pfsum.size(); i++){
            pfsum[i] = pfsum[i-1] + differences[i-1]; 
            // net_dif += differences[i-1];
        }
        long int range = *max_element(pfsum.begin(), pfsum.end()) - *min_element(pfsum.begin(), pfsum.end());
        long int ans = upper - lower + 1 - range;
        return  (ans >= 0) ? ans : 0 ;

    }
};