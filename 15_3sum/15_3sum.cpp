#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int vsize = nums.size(), lookup, p1, p2, p3;
        std::vector<vector<int>> result;
        for (p1 = 0; p1 < vsize - 1; ++p1) {
            /** Note1 
             * @brief The issue with checking the duplicate element refered by 
             * p1 by checking the element ahead at (p1+1) is that we will move
             * the p1 pointer ahead untill the last duplicate element of nums[p1]
             * for example -1 -1  0 1 2
             *              p1 p1 p2  p3
             * and then p2 will always start at the next element of p1. This 
             * might lead to cases where p2 can never be equal to p1 and will
             * lead to missing the cases where p2 + p3 are equal to target - p1
             * and only [-1 ,0 ,1 ] will be found where as [-1,-1,2] is also a 
             * valid result.
             * if ( nums[p1] == nums[p1 + 1]) {
             *   continue;
             * }
             * So we check for the duplicate element refered by p1 by looking 
             * backwards after p1 has become greater than 1 using the following 
             * updated if statement.
             */
            if (p1 > 0 && nums[p1] == nums[p1 - 1]) {
                continue;
            }

            lookup = -nums[p1];
            for (p2 = p1 + 1, p3 = vsize - 1; p2 < p3;) {
                if (nums[p2] + nums[p3] == lookup) {
                    result.push_back({nums[p1], nums[p2], nums[p3]});
                    while (p2 < p3 && nums[p2] == nums[p2 + 1]) {
                        p2++;
                    }
                    /**
                     * @brief This is not necessarily required as p1 is unique, 
                     * p2 is unique so the third element will be unique anyways
                     * for a sum of three numbers.
                     * 
                     */
                    // while (p2 < p3 && nums[p3] == nums[p3 - 1]) {
                    //     p3--;
                    // }
                    p2++;
                    p3--;
                } else if (nums[p2] + nums[p3] < lookup) {
                    p2++;
                } else {
                    p3--;
                }
            }
        }
        return result;
    }
};

//testing code for threeSum
int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}