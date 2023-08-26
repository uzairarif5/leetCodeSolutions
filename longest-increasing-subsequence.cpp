#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int ansArr[nums.size()];
        ansArr[0] = nums[0];
        for(int i = 0; i < nums.size(); i++){
            ansArr[i] = 1;
        }
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j]<nums[i] && ansArr[j]>=ansArr[i]) ansArr[i] = ansArr[j] + 1;
            }
            ans = max(ansArr[i],ans);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << sol.lengthOfLIS(nums) << endl;
    nums = {1,3,6,7,9,4,10,5,6};
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}