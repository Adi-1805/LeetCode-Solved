class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> hash(n+1);
        vector<int> C(n, 0);
        for(int i = 0; i < n; i++){
            hash[A[i]]++; hash[B[i]]++;
            int cnt = 0;
            for(int j = 0; j < n+1; j++){
                if(hash[j] == 2) cnt++;
            }
            C[i] = cnt;
        }
        return C;
    }
};