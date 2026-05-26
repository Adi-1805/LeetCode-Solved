class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<pair<int, int>> q; // {ind, steps}
        vector<int> vis(n, 0);
        unordered_map<int, vector<int>> val_idx;
        for(int i=0; i<n; i++) val_idx[arr[i]].push_back(i);
        q.push({0, 0});
        vis[0] = 1;
        while(!q.empty()){
            int ind = q.front().first, steps = q.front().second;
            q.pop();
            if(ind == n-1) return steps;
            if(ind-1 >= 0 and !vis[ind-1]){
                q.push({ind-1, steps+1}); vis[ind-1]=1;
            }
            if(ind+1 < n and !vis[ind+1]){
                q.push({ind+1, steps+1}); vis[ind+1]=1;
            }

            for(int idx: val_idx[arr[ind]]){
                if(idx != ind and !vis[idx]) { q.push({idx, steps+1}); vis[idx]=1; }
            }
            val_idx.erase(arr[ind]);
        }
        return -1;
    }
};