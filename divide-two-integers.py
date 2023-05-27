'''
Below converts number to binary
class Solution(object):
    powArr = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648]

    def divide(self, dividend, divisor):
        didBin = [0] * 32
        disBin = [0] * 32
        curDid = abs(dividend)
        curDis = abs(divisor)
        didLen = -1
        disLen = -1
        for i in range(31,-1,-1):
            if(curDid >= self.powArr[i]):
                curDid -= self.powArr[i]
                didBin[31-i] = 1
                if(didLen==-1):
                    didLen = 31-i
            if(curDis >= self.powArr[i]):
                curDis -= self.powArr[i]
                disBin[31-i] = 1
                if(disLen==-1):
                    disLen = 31-i
        print(didBin,bin(abs(dividend)))
        print(disBin,bin(abs(divisor)))
'''

class Solution(object):
    def divide(self, dividend, divisor):
        dn = abs(dividend)
        ds = abs(divisor)
        muldict = [1]
        muldict2 = [ds]
        while muldict2[-1] + muldict2[-1] <= dn:
            muldict.append(muldict[-1] + muldict[-1])
            muldict2.append(muldict2[-1] + muldict2[-1])
        curDiv = dn
        listForSum = []
        for i in range(len(muldict2)-1,-1,-1):
            if(curDiv - muldict2[i] >= 0):
                curDiv -= muldict2[i]
                listForSum.append(muldict[i])

        if((dividend < 0) ^ (divisor < 0)):
            return 0-sum(listForSum)
        else:
            output = sum(listForSum)
            if(output == 2**31):
                return output -1
            return output


sol = Solution()
dividend = 1245
divisor = 12
print(sol.divide(dividend,divisor))
print(bin(dividend))
print(dividend/divisor)