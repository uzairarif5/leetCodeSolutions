#include <iostream>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        if(word2 == "") return word1.length();
        if(word1=="") return word2.length();
        if(word1==word2) return 0;
        int table[word2.length()][word1.length()];
        int i;
        int useNeg = 0;
        for(i = 0; i<word1.length();i++){
            if(word2[0] == word1[i] && useNeg==0) useNeg = -1;
            table[0][i] = i+1+useNeg;
        }
        if(word2[0] != word1[0]) useNeg = 0;
        for(i = 1; i<word2.length();i++){ 
            if(word2[i] == word1[0] && useNeg==0) useNeg = -1;
            table[i][0] = i+1+useNeg;       
            for(int j = 1; j<word1.length();j++){
                if(word1[j]==word2[i]) table[i][j] = table[i-1][j-1];
                else{
                    table[i][j] = std::min(std::min(table[i-1][j], table[i][j-1])+1,table[i-1][j-1] + 1);
                }
            }
        }
        for(i = 0; i<word2.length();i++){ 
            for(int j = 0; j<word1.length();j++){
                std::cout << table[i][j] << " ";
            }
            std::cout << "\n";
        }
        return table[word2.length()-1][word1.length()-1];
    }
};

int main() {
    Solution sol;
    std::cout << sol.minDistance("sea","eat") << "\n\n";
    std::cout << sol.minDistance("a","ab") << "\n\n";
    std::cout << sol.minDistance("intention","execution") << "\n\n";
    std::cout << sol.minDistance("park","spake") << "\n\n";
    std::cout << sol.minDistance("teacher","stomacher") << "\n\n";
    return 0;
}