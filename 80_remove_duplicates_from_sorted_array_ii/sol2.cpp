#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int slow = 2;
        for (int fast = 2; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k1 = sol.removeDuplicates(nums1);
    cout << "Test Case 1 -> k: " << k1 << ", nums: ";
    cout << endl;

    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    // // Test case 2
    // vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    // int k2 = sol.removeDuplicates(nums2);
    // cout << "Test Case 2 - k: " << k2 << ", nums: ";
    // for(int i = 0; i < k2; i++) {
    //     cout << nums2[i] << " ";
    // }
    // cout << endl;

    // Add more test cases as needed

    return 0;
}