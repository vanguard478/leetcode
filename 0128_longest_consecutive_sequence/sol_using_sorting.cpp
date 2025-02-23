#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longestStreak = 0;
        int currentStreak = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == (nums[i - 1] + 1)) {
                    currentStreak += 1;
                } else {
                    longestStreak = max(currentStreak, longestStreak);
                    currentStreak = 1;
                }
            }
        }
        return longestStreak;
    }
};

//testing code for main
int main() {
    Solution sol;
    vector<int> nums = {100, 45, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}