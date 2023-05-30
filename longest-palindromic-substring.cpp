#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return "";
        string output = "";
        int maxIndex1=0;
        int maxIndex2=0;
        int max1=0;
        int max2=0;
        for (int i = 0; i < s.length()-1; i++) {
            int j = i;
            int k = i+1;
            int potentialMax1=0;
            while(j>=0 && k<s.length() && s[j]==s[k]){
                potentialMax1+=1;
                j-=1;
                k+=1;
            }
            if(potentialMax1>max1){
                max1 = potentialMax1;
                maxIndex1=i;
            }
            j = i-1;
            k = i+1;
            int potentialMax2=0;
            while(j>=0 && k<s.length() && s[j]==s[k]){
                potentialMax2+=1;
                j-=1;
                k+=1;
            }
            if(potentialMax2>max2){
                max2 = potentialMax2;
                maxIndex2 = i;
            }
        }
        if(max1>max2){
            return  s.substr(maxIndex1-max1+1, max1*2);
        }
        return s.substr(maxIndex2-max2, (max2*2)+1);
    }
};


int main(){
    Solution sol;
    cout << sol.longestPalindrome("cgfbabfgd")<<endl;
    cout << sol.longestPalindrome("cgfbfhnanhfbfgd")<<endl;
    cout << sol.longestPalindrome("babad")<<endl;
    cout << sol.longestPalindrome("cbghbjtlltjbhgbd")<<endl;
    return 0;
}