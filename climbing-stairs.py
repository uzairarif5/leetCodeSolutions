class Solution:
    storedAns = {1:1,2:2,3:3}
    def climbStairs(self, n):
        if n in self.storedAns:
            return self.storedAns[n]
        else:
            self.storedAns[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
            return self.storedAns[n]

sol = Solution()
print(sol.climbStairs(5))