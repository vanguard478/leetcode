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
            // while (p1 < vsize - 1 && nums[p1] == nums[p1 + 1]) {
            //     p1++;
            // }
            lookup = -nums[p1];
            for (p2 = p1 + 1, p3 = vsize - 1; p2 < p3;) {
                if (nums[p2] + nums[p3] == lookup) {
                    result.push_back({nums[p1],nums[p2],nums[p3]});
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