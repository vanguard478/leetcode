#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> num_set;
        for (auto i : nums) {
            num_set.insert(i);
        }
        int longestStreak = 0, currentStreak = 1, currentNum;
        for (auto i : num_set) {
            //if currentNum - 1 is in the set then current number must be part of
            //larger sequence so drop it and move onto the next num in set
            //If currenNum - 1 is not present then take this number as start
            //of the streak and start counting
            if (num_set.find(i - 1) == num_set.end()) {
                currentNum = i;

                currentStreak = 1;

                //Sequentially look for next consequtive number for the currentNum
                // and keep incrementing the currentNum and CurrentStreak untill
                // a next consequtive number is not found in the set.
                while (num_set.find(currentNum + 1) != num_set.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(currentStreak, longestStreak);
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