#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int longestStreak = 0;
        for (auto i : nums) {  // This will take O(n)
            int currentNum = i;
            int currentStreak = 1;
            //Keep updating the current streak and currentNum as
            //long as there is a next cosequtive number for the
            // currentNum.
            while (isInArray(currentNum + 1, nums)) {  //The function call is O(n)
                currentNum += 1;                       // Increments by 1 in the while Loop so O(n)
                currentStreak += 1;
            }
            longestStreak = max(currentStreak, longestStreak);
        }
        return longestStreak;
    } // Total Complexity is O(n^3)
    bool isInArray(int ele, vector<int> arr) {
        for (int i = 0; i < arr.size(); ++i) {
            if (ele == arr[i]) {
                return true;
            }
        }
        return false;
    }
};

//testing code for main
int main() {
    Solution sol;
    vector<int> nums = {100, 45, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}