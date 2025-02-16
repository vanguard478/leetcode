// [153. Find Minimum in Rotated Sorted Array]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        if (nums[left] <= nums[right]) {
            return nums[left];
        }
        while (left != right) {
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
            mid = left + (right - left) / 2;
        }
        return nums[left];;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,1};
    int minNum = sol.findMin(nums);
    cout << "Minimum number: " << minNum << endl;
    return 0;
}
