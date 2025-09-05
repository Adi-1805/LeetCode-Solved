class Solution {
    unordered_map<string, int> wordAtStep;
    vector<vector<string>> ans;

    void dfs(string word, vector<string> &seq, string target){
        if(word == target){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = wordAtStep[word];
        for(int i = 0; i < word.size(); i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(wordAtStep.find(word) != wordAtStep.end() and wordAtStep[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word, seq, target);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push({beginWord});
        wordAtStep[beginWord] = 1;
        if(st.count(beginWord) > 0) st.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            int steps = wordAtStep[word];
            q.pop();

            if(word == endWord) break;

            for(int i = 0; i < word.size(); i++){
                char orig = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        wordAtStep[word] = steps+1;
                    }
                }
                word[i] = orig;
            }
        } 
        if(wordAtStep.find(endWord) != wordAtStep.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq, beginWord);
        }
        return ans;
    }
};