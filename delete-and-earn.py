class Solution:
    def recurFunc(self,mulDict):
        if(len(mulDict)==2): return max(list(mulDict.values()))
        sortedKeyVals = sorted(list(mulDict.keys()))
        if(len(mulDict)==3): return max(mulDict[sortedKeyVals[1]],mulDict[sortedKeyVals[0]]+mulDict[sortedKeyVals[2]])
        if(len(mulDict)==4): return max(mulDict[sortedKeyVals[0]]+mulDict[sortedKeyVals[2]],mulDict[sortedKeyVals[0]]+mulDict[sortedKeyVals[3]],mulDict[sortedKeyVals[1]]+mulDict[sortedKeyVals[3]])
        mulDict[sortedKeyVals[2]] += mulDict[sortedKeyVals[0]]
        for i in range(3,len(mulDict)):
            mulDict[sortedKeyVals[i]] += max(mulDict[sortedKeyVals[i-3]],mulDict[sortedKeyVals[i-2]])
        return max(mulDict[sortedKeyVals[-2]],mulDict[sortedKeyVals[-1]])

    def deleteAndEarn(self,nums):
        mulDict = {}
        for val in nums:
            if(val in mulDict): mulDict[val] += val
            else: mulDict[val] = val
        keyVals = list(mulDict.keys())
        minimum = 0
        for key in keyVals:
            if not (key+1 in keyVals or key-1 in keyVals):
                minimum += mulDict[key]
                del mulDict[key]
        if(len(mulDict)>0):
            keyList = sorted(mulDict.keys())
            groups = [[keyList[0]]]
            for i in keyList[1:]:
                if(i == groups[-1][-1]+1):
                    groups[-1].append(i)
                else:
                    groups.append([i])
            for group in groups:
                tempDict = {}
                for i in group:
                    tempDict[i] = mulDict[i]
                if(len(tempDict)>0):
                    minimum += self.recurFunc(tempDict)
        return minimum
          
sol = Solution()
print("6",sol.deleteAndEarn([3,4,2]))
print("10",sol.deleteAndEarn([3,6,1]))
print("5",sol.deleteAndEarn([3,4,1]))
print("16",sol.deleteAndEarn([2,3,10,4]))
print("9",sol.deleteAndEarn([2,2,3,3,3,4]))
print("12",sol.deleteAndEarn([4,4,4]))
print("61",sol.deleteAndEarn([8,3,4,7,6,6,9,2,5,8,2,4,9,5,9,1,5,7,1,4]))
print(sol.deleteAndEarn([12,32,93,17,100,72,40,71,37,92,58,34,29,78,11,84,77,90,92,35,12,5,27,92,91,23,65,91,85,14,42,28,80,85,38,71,62,82,66,3,33,33,55,60,48,78,63,11,20,51,78,42,37,21,100,13,60,57,91,53,49,15,45,19,51,2,96,22,32,2,46,62,58,11,29,6,74,38,70,97,4,22,76,19,1,90,63,55,64,44,90,51,36,16,65,95,64,59,53,93]))
print(sol.deleteAndEarn([25,95,76,4,90,87,46,44,58,33,62,79,5,3,32,21,87,31,44,68,49,45,18,50,26,74,64,17,81,49,80,58,15,6,90,8,6,28,15,16,9,98,50,96,30,27,67,99,86,63,19,54,80,4,84,24,60,22,75,35,76,3,37,80,16,51,14,51,93,49,84,82,48,9,7,79,7,68,15,11,71,59,18,47,5,57,64,38,99,35,57,9,13,14,81,25,5,14,74,63,80,78,70,48,32,54,34,40,21,95,98,25,72,59,21,49,19,2,18,93,14,81,57,41,95,69,71,64,50,35,26,72,92,51,18,11,55,26,2,95,93,35,71,47,88,22,66,90,72,66,61,11,76,10,95,24,35,75,15,95,24,76,78,58,28,23,75,73,40,40,84,18,31,91,7,97,13,96,39,17,22,85,28,79,61,73,88,36,82,27,95,31,96,59,20,13,44,13,7,29]))