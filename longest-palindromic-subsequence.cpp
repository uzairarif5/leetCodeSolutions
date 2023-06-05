#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
using namespace std;

class Solution {
public:

    map<string, int> storedAns;

    ofstream outputFile;
    void openFile(){
        this->outputFile.open("output.txt");
    }

    void closeFile(){
        this->outputFile.close();
    }

    bool isPalindrome(string s){
        if(s.length()==1) return true;
        if(s.length()==2){
            if(s[0]==s[1]) return true;
            else return false;
        }
        if(s.length()==3){
            if(s[0]==s[2]) return true;
            else return false;
        }
        for(int i =0; i<s.length()/2;i++ ){if(s[i] != s[s.length()-i-1]) return false;}
        return true;
    }

    int longestPalindromeSubseq(string s) {
        for(int i=0;i<s.length();i++){
            string secondS = s;
            this->outputFile << secondS.erase(i,1) << "\n";
        }
        return 0;
    }
};

int main(){
    Solution sol;
    sol.openFile();
    cout << sol.longestPalindromeSubseq("abcde")<<endl;
    cout << sol.longestPalindromeSubseq("cbabbgab")<<endl;
    cout << sol.longestPalindromeSubseq("pfffft")<<endl;
    cout << sol.longestPalindromeSubseq("bandit")<<endl;
    cout << sol.longestPalindromeSubseq("racecar")<<endl;
    cout << sol.longestPalindromeSubseq("abcabcabcabc")<<endl;
    cout << sol.longestPalindromeSubseq("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew")<<endl;
    sol.closeFile();
    return 0;
}



/*


    map<string, int> storedAns;

    ofstream outputFile;
    void openFile(){
        this->outputFile.open("output.txt");
    }

    void closeFile(){
        this->outputFile.close();
    }

    bool isPalindrome(string s){
        if(s.length()==1) return true;
        if(s.length()==2){
            if(s[0]==s[1]) return true;
            else return false;
        }
        if(s.length()==3){
            if(s[0]==s[2]) return true;
            else return false;
        }
        for(int i =0; i<s.length()/2;i++ ){if(s[i] != s[s.length()-i-1]) return false;}
        return true;
    }

    bool checkAllOnes(vector<int> arr){
        for(int i =0; i<arr.size(); i++){if(arr[i] == 0) return false;}
        return true;
    }

    int longestPalindromeSubseq(string s) {
        vector<int> maskArr(s.length(), 0);
        int maxPalindrome = 1;
        while(!checkAllOnes(maskArr)){
            string secondS;
            for(int i =0; i<s.length(); i++){
                if(maskArr[i]==0) secondS.push_back(s[i]);
            }
            if(maxPalindrome<secondS.length()&&isPalindrome(secondS)) maxPalindrome = secondS.length();
            int i = s.length()-1;
            maskArr[i] += 1;
            while(maskArr[i]==2){
                maskArr[i] = 0;
                i--;
                maskArr[i] += 1;
            }
        }
        return maxPalindrome;
    }
*/

/*
Old code:
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    map<string, int> storedAns ={};

    ofstream outputFile;
    void openFile(){
        this->outputFile.open("output.txt");
    }

    void closeFile(){
        this->outputFile.close();
    }

    bool isPalindrome(string s){
        for(int i =0; i<s.length()/2;i++ ){if(s[i] != s[s.length()-i-1]) return false;}
        return true;
    }

    int longestPalindromeSubseq(string s) {
        this->outputFile << s << endl;
        if(s.length()==1) return 1;
        if(s.length()==2){
            if(s[0]==s[1]) return 2;
            else return 1;
        }
        if(s.length()==3){
            if(s[0]==s[2]) return 3;
            else if(s[0] == s[1] || s[1] == s[2]) return 2;
            else return 1;
        }
        if(this->storedAns.find(s) != this->storedAns.end()) return this->storedAns[s];
        else if (isPalindrome(s)){
            this->storedAns.insert(pair<string,int>(s,s.length()));
            return s.length();
        }
        else{
            int maxPalindrome = 1;
            for(int i=0;i<s.length();i++){
                string secondS = s;
                int potentialMax = longestPalindromeSubseq(secondS.erase(i,1));
                if (potentialMax > maxPalindrome) maxPalindrome = potentialMax;
            }
            this->storedAns.insert(pair<string,int>(s,maxPalindrome));
            return maxPalindrome;
        }
    }
};

int main(){
    Solution sol;
    sol.openFile();
    cout << sol.longestPalindromeSubseq("abcde")<<endl;
    cout << sol.longestPalindromeSubseq("bbbab")<<endl;
    cout << sol.longestPalindromeSubseq("pfffft")<<endl;
    cout << sol.longestPalindromeSubseq("bandit")<<endl;
    cout << sol.longestPalindromeSubseq("racecar")<<endl;
    cout << sol.longestPalindromeSubseq("abcabcabcabc")<<endl;
    cout << sol.longestPalindromeSubseq("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew")<<endl;
    sol.closeFile();
    return 0;
}
*/