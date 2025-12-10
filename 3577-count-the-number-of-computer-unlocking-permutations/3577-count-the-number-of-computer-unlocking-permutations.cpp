class Solution {
    const int M = 1000000007;
    long long factorial(int n) {
    if (n == 0) {
        return 1; // Factorial of 0 is 1
    }
    unsigned long long result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result = (result*i)%M;
    }
    return result;
}

public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int complex_0 = complexity[0];
        // the complexity of the 0th computer should be unique minimum value
        for(int i = 1; i < n; i++) if(complex_0 >= complexity[i]) return 0;
        // if the former is true, the order of rest of the elements is arbitrary
        return factorial(n-1);
    }
};