class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        long long outBeams = 0, inBeams = 0, answer = 0;
        int firstFilledRow = 0;
        // Finding the first filled row with devices
        while(outBeams == 0 and firstFilledRow < n){
            bitset<500> bits(bank[firstFilledRow]);
            outBeams = bits.count();
            firstFilledRow++;
        }
        // Proceeding with the later rows to multiply and propagate forward
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