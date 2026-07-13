#include <bits/stdc++.h>
#define el endl
#define ll long long int
#define ull unsigned long long int
#define f(i, initializer, upper_limit) for(ll i = initializer; i < upper_limit; i++)
#define rf(i, initializer, lower_limit) for(ll i = initializer; i > lower_limit; i--)
#define deb(x) cout << #x << " = " << x << nl;
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        f(i,0,n){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int j = i+1; int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){ 
                    ans.push_back({nums[i],nums[j++],nums[k--]});
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(sum<0) j++;
                else k--;
            }
        }
        return ans;
    }
};