class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            if(arr[ind] == 0) return true;
            if(ind-arr[ind] >= 0 and !vis[ind-arr[ind]]){
                q.push(ind-arr[ind]); vis[ind-arr[ind]]=1;
            }
            if(ind+arr[ind] < n and !vis[ind+arr[ind]]){
                q.push(ind+arr[ind]); vis[ind+arr[ind]]=1;
            }
        }
        return false;
    }
};