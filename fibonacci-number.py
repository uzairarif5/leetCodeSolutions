class Solution(object):
    def fib(self, n):
        if(n == 0):
            return 0 
        elif (n == 1):
            return 1
        else:
            return self.fib(n-1) + self.fib(n-2)

sol = Solution()
print("ANS",sol.fib(2))
print("ANS",sol.fib(3))
print("ANS",sol.fib(4))