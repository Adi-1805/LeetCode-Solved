class SegTree{
    int n; vector<int> maxi; vector<int> mini;

    public: 
    SegTree(vector<int> &nums){
        n = nums.size(); maxi.resize(4*n); mini.resize(4*n); 
        build(0, 0, n-1, nums);
    }

    void build(int node, int l, int r, vector<int> &nums){
        if(l == r) {
            maxi[node] = mini[node] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(2*node+1, l, mid, nums);
        build(2*node+2, mid+1, r , nums);
        maxi[node] = max(maxi[2*node+1], maxi[2*node+2]);
        mini[node] = min(mini[2*node+1], mini[2*node+2]);
    }

    int qMin(int node, int l, int r, int i, int j){
        if(i > r or j < l){
            return INT_MAX;
        }
        if(i <= l and j >= r) return mini[node];
        int mid = (l+r)/2;
        int left = qMin(2*node+1, l, mid, i, j); 
        int right = qMin(2*node+2, mid+1, r, i, j); 
        return min(left, right);
    }

    int qMax(int node, int l, int r, int i, int j){
        if(i > r or j < l){
            return INT_MIN;
        }
        if(i <= l and j >= r) return maxi[node];
        int mid = (l+r)/2;
        int left = qMax(2*node+1, l, mid, i, j); 
        int right = qMax(2*node+2, mid+1, r, i, j); 
        return max(left, right);
    }
};
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree seg(nums);
        priority_queue<tuple<int, int, int>> pq;
        for(int l=0; l < n; l++){
            pq.emplace(seg.qMax(0, 0, n-1, l, n-1) - seg.qMin(0, 0, n-1, l, n-1), l, n-1);
        }
        long long ans = 0;
        while(k--){
            auto [val, l, r] = pq.top(); pq.pop();
            ans += val;
            if(r > l) pq.emplace(seg.qMax(0, 0, n-1, l, r-1) - seg.qMin(0, 0, n-1, l, r-1), l, r-1);
        }
        return ans;
    }
};