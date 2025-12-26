class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int y_cnt = count(customers.begin(), customers.end(), 'Y'), n_cnt = 0;
        if(y_cnt == n) return n;
        int min_penalty = INT_MAX, closing_time = 0; 
        for(int i = 0; i < n; i++){
            int penalty = y_cnt + n_cnt;
            if(min_penalty > penalty){
                closing_time = i;
                min_penalty = penalty;
            } 
            if(customers[i] == 'N') n_cnt++;
            if(customers[i] == 'Y') y_cnt--;
        }
        if(min_penalty > y_cnt + n_cnt) closing_time = n;
        return closing_time;
    }
};