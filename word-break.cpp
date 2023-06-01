#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    Solution sol;
    vector<string> strInput;
    strInput = {"a","aa","aaaa","aaaaaaaa","aaaaa"};
    cout<<"sol: "<< sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", strInput) <<endl;
    strInput = {"leet","code"};
    cout<<"sol: "<< sol.wordBreak("leetcode", strInput) <<endl;
    strInput = {"a"};
    cout<<"sol: "<< sol.wordBreak("a", strInput) <<endl;
    strInput = {"car","ca","rs"};
    cout<<"sol: "<< sol.wordBreak("cars", strInput) <<endl;
    strInput = {"bc","cb"};
    cout<<"sol: "<< sol.wordBreak("ccbb", strInput) <<endl;
    strInput = {"cc","ac"};
    cout<<"sol: "<< sol.wordBreak("ccaccc", strInput) <<endl;
    strInput = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"};
    cout<<"sol: "<< sol.wordBreak("bccdbacdbdacddabbaaaadababadad", strInput) <<endl;
    return 0;
}