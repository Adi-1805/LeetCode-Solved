class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        long long outBeams = 0, inBeams = 0, answer = 0;
        int firstFilledRow = 0;
        while(outBeams == 0 and firstFilledRow < n){
            bitset<500> bits(bank[firstFilledRow]);
            outBeams = bits.count();
            firstFilledRow++;
        }
        cout << outBeams << endl;
        for(int i = firstFilledRow; i < n; i++){
            bitset<500> bits(bank[i]);
            inBeams = bits.count();
            if(inBeams != 0 and outBeams != 0){
                answer += 1LL*inBeams*outBeams;
                outBeams = inBeams;
            }
        }
        return answer;
    }
};