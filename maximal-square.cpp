#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxValue =0;
        int dp[matrix.size()][matrix[0].size()];
        for(int i=0;i<matrix.size();i++){
            for(int j =0;j<matrix[0].size();j++){
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    dp[i][j] = 1;
                    maxValue =1;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j =1;j<matrix[0].size();j++){
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    int minPrevNum = min(dp[i][j-1],dp[i-1][j]);
                    minPrevNum = min(dp[i-1][j-1],minPrevNum);
                    if(minPrevNum != 0){
                        dp[i][j] = minPrevNum+1;
                        maxValue = max(minPrevNum+1,maxValue);
                    }
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j =0;j<matrix[0].size();j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return maxValue*maxValue;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> matInput;
    matInput = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout <<"sol: "<< sol.maximalSquare(matInput) << endl;
    matInput = {{'0','1'},{'1','0'}};
    cout  <<"sol: "<< sol.maximalSquare(matInput) << endl;
    matInput = {{'0'}};
    cout  <<"sol: "<< sol.maximalSquare(matInput) << endl;
    matInput = {{'1','1'},{'1','1'}};
    cout  <<"sol: "<< sol.maximalSquare(matInput) << endl;
    matInput = {{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','1','1','1'}};
    cout  <<"sol: "<< sol.maximalSquare(matInput) << endl;
    return 0;
}