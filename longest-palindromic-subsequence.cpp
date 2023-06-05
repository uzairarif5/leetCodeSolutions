#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
using namespace std;

class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int subseqMatrix[s.length()][s.length()];
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<s.length(); j++){
                subseqMatrix[i][j] = 0;
            }
        }
        for(int i=0;i<s.length();i++){
            subseqMatrix[i][i] = 1;
        }
        for(int i=s.length()-2;i>=0;i--){
            if(s[i] == s[i+1]) subseqMatrix[i][i+1] = 2;
            else subseqMatrix[i][i+1] = 1;
            for(int j=i+2;j<s.length();j++){
                if(s[i] == s[j]) subseqMatrix[i][j] = 2 + subseqMatrix[i+1][j-1];
                else subseqMatrix[i][j] = max(subseqMatrix[i][j-1],subseqMatrix[i+1][j]);
            }
        }
        return subseqMatrix[0][s.length()-1];
    }
};

int main(){
    Solution sol;
    cout << sol.longestPalindromeSubseq("abcde")<<endl;
    cout << sol.longestPalindromeSubseq("cbabbgab")<<endl;
    cout << sol.longestPalindromeSubseq("pfffft")<<endl;
    cout << sol.longestPalindromeSubseq("bandit")<<endl;
    cout << sol.longestPalindromeSubseq("racecar")<<endl;
    cout << sol.longestPalindromeSubseq("abcabcabcabc")<<endl;
    cout << sol.longestPalindromeSubseq("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew")<<endl;
    return 0;
}