class Solution {
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(int num: nums){
            maxi = max(maxi, num); mini = min(mini, num);
        }
        return gcd(maxi, mini);
    }
};