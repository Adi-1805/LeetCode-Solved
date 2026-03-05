using ll = long long;
class Solution {
    vector<int> arr;
    class RangeMinQuery{
        vector<ll> seg;
        public:
        RangeMinQuery(int N){
            seg.assign(4*N, 1e9);
        }
        void build(int ind, int low, int high, vector<int> &arr){
            if(low == high) { 
                seg[ind] = arr[low]; return; 
            }
            int mid = (low + high) >> 1;
            build(2*ind+1, low, mid, arr); build(2*ind+2, mid+1, high, arr);
            seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
        }
        ll query(int ind, int low, int high, int l, int r){
            if(high < l or r < low) return 1e9;
            if(low >= l and high <= r) return seg[ind];
            ll mid = (low+high) >> 1;
            int left = query(2*ind+1, low, mid, l, r);
            int right = query(2*ind+2, mid+1, high, l, r);
            return min(left, right);
        }
    };
    class RangeMaxQuery{
        vector<ll> seg;
        public:
        RangeMaxQuery(int N){
            seg.assign(4*N, -1e9);
        }
        void build(int ind, int low, int high, vector<int> &arr){
            if(low == high) { 
                seg[ind] = arr[low]; return; 
            }
            int mid = (low + high) >> 1;
            build(2*ind+1, low, mid, arr); build(2*ind+2, mid+1, high, arr);
            seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
        }
        ll query(int ind, int low, int high, int l, int r){
            if(high < l or r < low) return -1e9;
            if(low >= l and high <= r) return seg[ind];
            ll mid = (low+high) >> 1;
            int left = query(2*ind+1, low, mid, l, r);
            int right = query(2*ind+2, mid+1, high, l, r);
            return max(left, right);
        }
    };
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n = nums.size(), ans = 0, i = 0, j = 0;
        RangeMinQuery mn(n);
        RangeMaxQuery mx(n);
        mn.build(0, 0, n-1, nums);
        mx.build(0, 0, n-1, nums);
        while(j<n){
            while((mx.query(0, 0, n-1, i, j) - mn.query(0, 0, n-1, i, j)) * (j-i+1) > k) i++;
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};