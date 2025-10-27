class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        long long outBeams = 0, inBeams = 0, answer = 0;
        for(int i = 0; i < n; i++){
            bitset<500> bits(bank[i]);
            inBeams = bits.count();
            if(inBeams != 0){
                answer += 1LL*inBeams*outBeams;
                outBeams = inBeams;
            }
        }
        return answer;
    }
};