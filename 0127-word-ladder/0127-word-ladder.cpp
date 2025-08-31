class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words(wordList.begin(), wordList.end());

        int noOfWords = 0;
        queue<pair<string, int>> q; q.push({beginWord, 1});
        while(!q.empty()){
            auto [str, len] = q.front();
            // cout << str << " " << len << endl; 
            if(str == endWord) return len;
            q.pop();
            for(int i = 0; i < str.size(); i++){
                for(int j = 0; j < 26; j++){
                    string newS = str;
                    newS[i] = char('a'+j);
                    if(words.count(newS) != 0){
                        q.push({newS, len+1});
                        words.erase(newS);
                    }
                }
            }
        }
        return 0;
    }
};