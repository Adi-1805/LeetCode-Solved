class Solution:
    def nthfib(self, n, dp):
        if dp[n] != -1:
            return dp[n]
        else:
            dp[n] = self.nthfib(n - 1, dp) + self.nthfib(n - 2, dp)
            return dp[n]

    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        dp = [-1] * (n + 1) 
        dp[0], dp[1] = 0, 1   
        
        return self.nthfib(n, dp)
