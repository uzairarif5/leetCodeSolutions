#include <iostream>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        for (int i = triangle.size()-1; i >= 1; i--){
            for (int j = 1; j < triangle[i].size(); j++){
                if(triangle[i][j]<triangle[i][j-1]) triangle[i-1][j-1] = triangle[i-1][j-1]+triangle[i][j];
                if(triangle[i][j]>=triangle[i][j-1]) triangle[i-1][j-1] = triangle[i-1][j-1]+triangle[i][j-1];
            }
        }
        return triangle[0][0];
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> triangle = {{2},{3,4},{5,6,7},{1,6,8,9},{6,8,9,1,2}};
    sol.minimumTotal(triangle);
    triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    sol.minimumTotal(triangle);
    return 0;
}