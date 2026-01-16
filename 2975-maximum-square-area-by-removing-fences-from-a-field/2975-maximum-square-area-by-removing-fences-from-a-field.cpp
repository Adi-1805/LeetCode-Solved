const int M = 1e9+7;
class Solution {
    unordered_set<int> getEdge(vector<int>& fences) {
        unordered_set<int> st;
        for (int i = 0; i < fences.size(); i++) {
            for (int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); vFences.push_back(1); sort(hFences.begin(), hFences.end());
        hFences.push_back(m); vFences.push_back(n); sort(vFences.begin(), vFences.end());
        
        auto hEdge = getEdge(hFences), vEdge = getEdge(vFences);
        int side = 0;
        for(auto &edge: hEdge){
            if(vEdge.count(edge) > 0){
                side = max(side, edge);
            }
        }
        return (side == 0) ? -1 : (1LL*side*side)%M;
    }
};