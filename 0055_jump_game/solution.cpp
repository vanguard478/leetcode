
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#include <gtest/gtest.h>

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i) {
            if (i > reachable) {
                return false;
            }

            reachable = std::max(i + nums[i], reachable);
        }

        return true;
    }
};

TEST(CanJumpTest, Example1) {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    EXPECT_TRUE(sol.canJump(nums));
}

TEST(CanJumpTest, Example2) {
    Solution sol;
    vector<int> nums = {3, 2, 1, 0, 4};
    EXPECT_FALSE(sol.canJump(nums));
}
TEST(CanJumpTest, Example3) {
    Solution sol;
    vector<int> nums = {2, 3, 0, 1, 4};
    EXPECT_TRUE(sol.canJump(nums));

}