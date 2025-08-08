class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextRow(2, 0);
        // return f(prices, 0, 1);

        for(int ind = n-1; ind >= 0; ind--){
            long profit = -1e9; vector<int> curr(2, 0);
            for(int buy = 0; buy < 2; buy++){
                if(buy){
                    profit = max( -arr[ind] + nextRow[0] , 0 + nextRow[1] );
                }else{
                    profit = max( arr[ind] + nextRow[1] , 0 + nextRow[0] );
                }
                curr[buy] = profit; 
            }
            nextRow = curr;
        }
        return nextRow[1];
    }
};