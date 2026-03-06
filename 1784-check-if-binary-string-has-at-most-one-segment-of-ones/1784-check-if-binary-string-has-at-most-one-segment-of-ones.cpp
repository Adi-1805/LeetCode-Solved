class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size(), l = 0;
        bitset<100> bits(s);
        int onecnt = bits.count();
        int curcnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') curcnt++;
            else{
                return (curcnt == onecnt);
            }
        }
        return true;
    }
};