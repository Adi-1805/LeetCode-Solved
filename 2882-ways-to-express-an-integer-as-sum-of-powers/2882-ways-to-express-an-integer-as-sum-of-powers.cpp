class Solution {
    const int M = 1e9+7;
    vector<int> findArr(int n, int x){
        vector<int> arr;
        int num = 0, i = 1;
        while(true){
            num = pow(i, x);
            if(num > n) break; 
            arr.push_back(num);
            i++;
        }
        return arr;
    }
public:
    int numberOfWays(int n, int x) {
        vector<int> arr = findArr(n, x);
        // vetor<vector<int>> dp(arr.size(), vector<int>(n+1, 0));
        vector<int> prev(n+1, 0);
        prev[0] = prev[arr[0]] = 1;
        
        for(int ind = 1; ind < arr.size(); ind++){
            vector<int> cur(n+1, 0);
            cur[0] = 1;
            for(int tar = 1; tar <= n; tar++){
                int not_pick = prev[tar]%M, pick = 0;
                if(arr[ind] <= tar) pick = prev[tar-arr[ind]]%M;
                cur[tar] = (pick + not_pick)%M;
            }
            prev = cur;
        }

        return prev[n];
    }
};