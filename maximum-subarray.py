'''
class Solution(object):
    def maxSubArray(self, nums):
        if(len(nums)==1): return nums[0]
        sum = nums[0]
        maxSum = sum
        for i in range(1,len(nums)):
            if(sum<0): sum = 0
            sum += nums[i]
            maxSum = max(maxSum,sum)
        return maxSum
'''

class Solution(object):
    def maxSubArray(self, nums):
        if(len(nums)==1): return nums[0]
        sum = nums[0]
        maxSum = sum
        for i in range(1,len(nums)):
            if(sum<0): sum = 0
            sum += nums[i]
            maxSum = max(maxSum,sum)
        return maxSum

sol = Solution()
print(6,sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
print(23,sol.maxSubArray([5,4,-1,7,8]))
print(1,sol.maxSubArray([1]))