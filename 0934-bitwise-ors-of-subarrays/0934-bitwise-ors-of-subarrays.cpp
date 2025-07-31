class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        set<int> ans;
        set<int> prev;

        for(int val: arr){
            set<int> curr;
            curr.insert(val);
            for(int ors: prev){
                curr.insert(ors | val);
            }
            prev = curr;
            ans.insert(prev.begin(), prev.end());
        }

        return ans.size();
    }
};