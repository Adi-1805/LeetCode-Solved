class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i <= n-k; i++){
            unordered_map<int,int>mp;
            for(int j = i; j < i + k; j++){
                mp[nums[j]]++;
            }
            priority_queue< pair<int,int> >pq;
            for(auto &it : mp){
                pq.push({it.second,it.first});
            }
            int sum = 0;
            int time = x;
            while(time > 0 && !pq.empty()){
                int num = pq.top().second;
                num = num * (pq.top().first);
                sum += num;
                pq.pop();
                time--;
                
            }
            ans.push_back(sum);

        }
        return ans;
    }
};