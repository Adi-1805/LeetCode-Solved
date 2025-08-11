class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& arr) {
        long long sum = 0;
        int mod = 1e9+7;
        vector<int> v;
        for(int i=0;i<32;i++) if( (n>>i & 1) ==1 ) v.push_back(i);
        for(int i=1;i<v.size();i++) v[i] += v[i-1];
        
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int l = arr[i][0] , r = arr[i][1], res = 1,c=0;
            if(l==0) c = v[r];
            else c = v[r] - v[l-1];
            while(c--) res = res*2 %mod;
            ans.push_back(res);
        }
        return ans;
    }
};