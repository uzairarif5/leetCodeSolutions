
class Solution:
    def robPart1(self,nums):
        for i in range(2,len(nums)):
            nums[i] += max(nums[:i-1])
        return max(nums[-1],nums[-2])

    def rob(self,nums):
        if(len(nums) <= 3): return max(nums)
        if(len(nums) == 4): return max(nums[0]+nums[2],nums[1]+nums[3])
        return max(self.robPart1(nums[1:]),self.robPart1(nums[:-1]))

sol = Solution()
print("10", sol.rob([2,2,4,3,2,5]))
print("340", sol.rob([200,3,140,20,10]))
print("3", sol.rob([1,2,1,1]))
print("103", sol.rob([1,3,1,3,100]))
print("3", sol.rob([2,3,2]))
print("41", sol.rob([1,1,3,6,7,10,7,1,8,5,9,1,4,4,3]))
print("25", sol.rob([2,1,2,6,1,8,10,10]))
print("1706", sol.rob([55,72,209,143,216,220,122,115,87,227,220,161,79,230,55,56,56,178,124,88,202,65,102]))