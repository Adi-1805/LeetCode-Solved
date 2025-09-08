class Solution {
    bool check(int num){
        string s = to_string(num);
        return !s.contains('0');
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2,0);
        for(int i = 1; i < n; i++){
            int a = i; int b = n-i;
            if(check(a) and check(b)){
                ans[0] = a, ans[1] = b;
                break;
            }
        }
        return ans;
    }
};