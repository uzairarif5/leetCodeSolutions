class Solution(object):

    def __init__(self):
        self.dp = []

    def longestPalindromeSubseq(self, s):
        n = len(s)
        self.dp = [[0]*n for _ in range(n)]
        
        for i in range(n-1, -1, -1):
            self.dp[i][i] = 1
            for j in range(i+1, n):
                if s[i] == s[j]:
                    self.dp[i][j] = 2 + self.dp[i+1][j-1]
                else:
                    self.dp[i][j] = max(self.dp[i+1][j], self.dp[i][j-1])
                    
        return self.dp[0][n-1]
    
    def showDpArray(self):
        print()
        for i in range(0, len(self.dp)):
            for j in self.dp[i]:
                print(j ,end=" ")
            print()


if (__name__ == "__main__"):
    sol = Solution()
    print(sol.longestPalindromeSubseq("bcbbab"))
    sol.showDpArray()
    print(sol.longestPalindromeSubseq("pfffft"))
    print(sol.longestPalindromeSubseq("bandit"))
    print(sol.longestPalindromeSubseq("racecar"))
    print(sol.longestPalindromeSubseq("abcabcabcabc"))
    print(sol.longestPalindromeSubseq("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew"))