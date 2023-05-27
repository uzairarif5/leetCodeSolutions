from inspect import stack


class Solution(object):
    def removeDuplicates(self, s, k):
        i = 0
        stack1 = []
        stack2 = []
        while i < len(s):
            if(len(stack1)!=0 and stack1[-1] == s[i]):
                stack2[-1] += 1
                if(stack2[-1] == k):
                    stack1.pop()
                    stack2.pop()
            else:
                stack1.append(s[i])
                stack2.append(1)
            i += 1
        outcome = ""
        for i in range(len(stack2)):
            for j in range(stack2[i]):
                outcome += stack1[i]
        return outcome

sol = Solution()
print("ANS",sol.removeDuplicates('deeedbbcccbdaa',3))
print("ANS",sol.removeDuplicates('pbbcggttciiippooaais',2))
print("ANS",sol.removeDuplicates('yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy',4))