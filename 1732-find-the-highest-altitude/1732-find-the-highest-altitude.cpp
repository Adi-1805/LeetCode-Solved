class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int prev = 0, curr = 0, ans = prev;
        for(int i = 1; i<n+1; i++){
            curr = prev + gain[i-1];
            ans = max(ans, curr);
            prev = curr;
        }
        return ans;
    }
};