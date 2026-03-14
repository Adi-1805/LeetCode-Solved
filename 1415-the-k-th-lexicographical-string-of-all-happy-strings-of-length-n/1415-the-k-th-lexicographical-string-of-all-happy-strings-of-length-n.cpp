class Solution {
    void recur(string s, int ind, int n, vector<string>& list){
        if(ind == n){
            list.push_back(s); return;
        }

        if(s.empty()){
            recur(s+'a', ind+1, n, list);
            recur(s+'b', ind+1, n, list);
            recur(s+'c', ind+1, n, list);
        }
        else if(s.back() == 'a'){
            recur(s+'b', ind+1, n, list);
            recur(s+'c', ind+1, n, list);
        }
        else if(s.back() == 'b'){
            recur(s+'a', ind+1, n, list);
            recur(s+'c', ind+1, n, list);
        }
        else if(s.back() == 'c'){
            recur(s+'a', ind+1, n, list);
            recur(s+'b', ind+1, n, list);
        }

    }
public:
    string getHappyString(int n, int k) {
        vector<string> list;
        recur("", 0, n, list);
        return (list.size() >= k) ? list[k-1] : ""; 
    }
};