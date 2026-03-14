class Solution {
    void recur(string s, int ind, int n, int k, vector<string>& list){
        if(ind == n){
            list.push_back(s);
            return;
        }

        if(s.empty()){
            recur(s+'a', ind+1, n, k-1, list);
            recur(s+'b', ind+1, n, k-1, list);
            recur(s+'c', ind+1, n, k-1, list);
        }
        else if(s.back() == 'a'){
            recur(s+'b', ind+1, n, k-1, list);
            recur(s+'c', ind+1, n, k-1, list);
        }
        else if(s.back() == 'b'){
            recur(s+'a', ind+1, n, k-1, list);
            recur(s+'c', ind+1, n, k-1, list);
        }
        else if(s.back() == 'c'){
            recur(s+'a', ind+1, n, k-1, list);
            recur(s+'b', ind+1, n, k-1, list);
        }

    }
public:
    string getHappyString(int n, int k) {
        vector<string> list;
        recur("", 0, n, k, list);
        for(string s: list) cout << s << " "; cout << endl;
        return (list.size() >= k) ? list[k-1] : ""; 
    }
};