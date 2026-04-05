class Solution {
public:
    bool judgeCircle(string moves) {
        int nL = 0, nR = 0, nU = 0, nD = 0;
        for(char ch: moves){
            if(ch == 'R') nR++;
            else if(ch == 'L') nL++;
            else if(ch == 'U') nU++;
            else if(ch == 'D') nD++;
        }
        return (nU == nD and nL == nR) ? 1 : 0;
    }
};