class Solution {
    vector<int> arr = {2, 4, 6, 8};
public:
    bool reorderedPowerOf2(int n) {
        vector<int> hsh1(10, 0);
        string orig = to_string(n);
        for(int i = 0; i < orig.size(); i++){
            hsh1[orig[i]-'0']++;
        }
        for(int i = 0; i < 32; i++){
            int num = (1 << i);
            vector<int> hsh2(10, 0);
            string pow2 = to_string(num);
            if(pow2.size() != orig.size()) continue;

            for(int j = 0; j < pow2.size(); j++){
                hsh2[pow2[j]-'0']++;
            }

            if(hsh1 == hsh2) return true;
        }
        return 0;
    }
};