class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        cnt, res = 0, ''
        for c in S:
            if c == ')': cnt -= 1  
            if cnt != 0: res += c 
            if c == '(': cnt+=1    
        return res