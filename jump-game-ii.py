class Solution(object):
    def jump(self, nums):
        if(len(nums)==1): return 0
        if(len(nums)==2): return 1
        if(len(nums)==3): 
            if(nums[0]>1): return 1
            else: return 2
        jumps = [len(nums)] * len(nums)
        for j in range(1,nums[0]+1):
            if(j==len(nums)): return 1
            jumps[j] = 1
        for i in range(1,len(nums)):
            curJumpVal = jumps[i]+1
            for j in range(1,nums[i]+1):
                if(i+j >= len(nums)):
                    break
                jumps[i+j] = min(jumps[i+j],curJumpVal)
        return(jumps[-1])

        

sol = Solution()
print(2,sol.jump([2,3,1,1,4]))
print(2,sol.jump([2,3,0,1,4]))
print(3,sol.jump([1,1,1,1]))