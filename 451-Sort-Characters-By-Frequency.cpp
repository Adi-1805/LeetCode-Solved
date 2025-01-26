class Solution {
public:
    string frequencySort(string s) {
        string result = \\;
        vector<pair<int, char>> arr(62, make_pair(0,'\\0'));
        for(char ch: s){
            if(islower(ch)){
                arr[ch-'a'].second = ch;
                arr[ch-'a'].first += 1;
            }
            else if(isupper(ch)){
                arr[ch-'A'+26].second = ch;
                arr[ch-'A'+26].first += 1;
            }
            else{
                arr[ch-'0'+52].second = ch;
                arr[ch-'0'+52].first += 1;
            }
        }
        sort(arr.begin(), arr.end(), greater<>());
        for(int i = 0; i < 62; i++){
            string temp(arr[i].first, arr[i].second);
            result += temp;
        }
        return result;
    }
};