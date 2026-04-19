class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] > B[j]) i++;
            j++;
        }
        // j - i is the farthest gap reached so far
        // subtract 1 since j is one step past it
        return max(0, j - i - 1); //  cannot be negative.
    }
};