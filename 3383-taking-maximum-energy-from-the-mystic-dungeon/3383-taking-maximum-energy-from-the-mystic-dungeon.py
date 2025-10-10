class Solution:
    def maximumEnergy(self, a: List[int], k: int) -> int:
        return max(max(accumulate(a[~i::-k])) for i in range(k))