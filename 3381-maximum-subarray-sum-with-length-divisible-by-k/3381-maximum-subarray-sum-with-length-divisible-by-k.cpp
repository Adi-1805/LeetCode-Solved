class Solution {
public:
    long long maxSubarraySum(vector<int>& nums,  int k) {
        int const N = (int)nums.size();
        
        long long maxSum = 2 * 100000 * -1000000000ll;

        long long windowSum = 0;
        vector<long long> lenKSum(N, -1);
        for (int l=0, r=0;  r<N;  ) { //precompute sums in size k windows
            while (r-l+1 <= k) {    //make sure the window is big enough
                windowSum += nums[r];
                ++r;
            }   //r is after the window here
            lenKSum[r-1] = windowSum;
            maxSum = max(maxSum, windowSum);

            windowSum -= nums[l]; //the next window does not need the furthest left endpoint
            ++l;
        }

        //are we able to improve any window by adding previous windows?
        for (int i = 2*k-1;  i<N;  ++i) {
            lenKSum[i] = max(lenKSum[i],  lenKSum[i] + lenKSum[i-k]);
            maxSum = max(maxSum, lenKSum[i]);
        }

        return maxSum;
    }
};