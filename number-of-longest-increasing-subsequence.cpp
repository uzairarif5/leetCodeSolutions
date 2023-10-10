#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int temp[nums.size()][2];
        for(int i=1;i<nums.size() ;i++){
            temp[i][0] = 0;
            temp[i][1] = 1;
        }
        temp[0][0] = 1;
        temp[0][1] = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if((nums[j]<nums[i]) && (temp[j][0] > temp[i][0])) temp[i][0] = temp[j][0];
            }
            int NumOfMaxSubNumBefore = 0;
            for(int j=i-1;j>=0;j--){
                if((nums[j]<nums[i]) && (temp[j][0] == temp[i][0])) NumOfMaxSubNumBefore += temp[j][1];
            }
            temp[i][0] = temp[i][0]+1;
            if(NumOfMaxSubNumBefore>1) temp[i][1] = NumOfMaxSubNumBefore;
        }

        for(int i=0;i<nums.size();i++) cout<<nums[i]<<" "<<temp[i][0]<<" "<<temp[i][1] << endl;
        int maxSub = 0;
        for(int i=0;i<nums.size();i++) {
            if(temp[i][0] > maxSub) maxSub = temp[i][0];
        };
        int maxSubTotalNum = 0;
        for(int i=0;i<nums.size();i++) {
            if(temp[i][0] == maxSub) maxSubTotalNum += temp[i][1];
        };
        return maxSubTotalNum;
    }
};

int main(){
    Solution sol;
    vector<int> input = {2, 3, 5, 4, 7, 1};
    cout << "sol: " << sol.findNumberOfLIS(input) << endl;
    input = {2, 2, 2, 2, 2};
    cout << "sol: " << sol.findNumberOfLIS(input) << endl;
    input = {1, 2, 4, 3, 5, 4, 7, 2};
    cout << "sol: " << sol.findNumberOfLIS(input) << endl;
    return 0;
}