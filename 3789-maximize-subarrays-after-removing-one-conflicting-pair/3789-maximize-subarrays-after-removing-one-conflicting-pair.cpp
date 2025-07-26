#define ll long long int
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        ll valid = 0;
        vector<vector<int>> conflictingPoints(n+1);
        for(auto& p: conflictingPairs){
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);
            conflictingPoints[b].push_back(a);
        }
        ll maxConflict = 0;
        ll secondmaxConflict = 0;

        vector<ll> extra(n+1, 0);

        for(int end = 1; end <= n; end++){
            for(auto& u: conflictingPoints[end]){
                if(u >= maxConflict){
                    secondmaxConflict = maxConflict;
                    maxConflict = u;
                }else if(u > secondmaxConflict){
                    secondmaxConflict = u;
                }
            }
            valid += end - maxConflict;
            if(maxConflict > 0){
                extra[maxConflict] += maxConflict - secondmaxConflict;
            }
        }
        return valid + *max_element(begin(extra), end(extra));
    }
};