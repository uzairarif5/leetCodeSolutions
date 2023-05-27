class Solution(object):
    def twoSum(self, nums, target):
        for i1 in range(len(nums)):
            for i2 in range(i1+1,len(nums)):
                if(nums[i1] + nums[i2] == target):
                    return [i1,i2]
        
sol = Solution()
print(sol.twoSum([3,3],6))