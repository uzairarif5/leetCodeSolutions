class Solution:
    def rob(self, nums):
        if(len(nums) == 1): return nums[0]
        if(len(nums) > 2):
            for i in range(2,len(nums)):
                nums[i] += max(nums[:i-1])
        return max(nums[-1],nums[-2])

sol = Solution()
print(sol.rob([2,1,1,2]))