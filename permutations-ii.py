class Solution(object):
    def helper(self,k,nums):
        outcome = []
        for curP in nums:
            outcome += [curP.copy()]
            firstPointer = 0
            while firstPointer+k<len(curP):
                tempCurP = curP.copy()
                tempCurP[firstPointer],tempCurP[firstPointer+k] = tempCurP[firstPointer+k], tempCurP[firstPointer]
                outcome += [tempCurP]
                firstPointer+=1
        if(k>1):
            return self.helper(k-1,outcome.copy())
        else:
            return outcome.copy()

    def permuteUnique(self, nums):
        if(len(nums)==1):
            return  [nums]
        else:
            return self.helper(len(nums)-1,[nums.copy()])

sol = Solution()
file = open("output.txt","w")
output = sol.permuteUnique([1,2,3,4,5])
counter = 1
for i in output:
    print(output.count(i),i)
    file.write(str(i)+'\n')
    if(counter%5==0):
        file.write('\n')
    if(counter%20==0):
        file.write('\n')
    counter +=1
file.close()