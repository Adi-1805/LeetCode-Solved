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
        for(int i = 1; i < n; i++){
            if(complexity[i] == complex_0) return 0;
        }
        if(complex_0 != *min_element(complexity.begin(), complexity.end())) return 0;
        return factorial(n-1);
    }
};