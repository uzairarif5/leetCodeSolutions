class Solution(object):

    def combinationSum3(self, k, n):
        curArr = list(range(1,k+1))
        if(sum(curArr) > n): return []
        else:
            outcome = []
            flag = True
            while flag:
                #go through all the combinations of range(1,k+1) and take all the ones that sum to n
                if sum(curArr) == n: outcome.append(curArr.copy())
                if(curArr[-1]==9):
                    j = 2
                    while j <= len(curArr):
                        if(curArr[-j]==curArr[1-j]-1): j+=1
                        else: break
                    if(curArr[0] == 10-len(curArr)): flag = False
                    else:
                        curArr[-j] += 1
                        j -= 1
                        while j > 0:
                            curArr[-j] = curArr[-j-1] + 1
                            j -= 1
                else: curArr[-1] += 1
            return outcome
        
sol = Solution()
print(sol.combinationSum3(5,20))