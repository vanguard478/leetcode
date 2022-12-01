
#include <iostream>
#include <string>
#include <vector>
class Solution {
   public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid = low + (high - low) / 2;

        while (low <= high) {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target) {
                high = mid - 1;
            } else
                low = mid + 1;
            mid = low + (high - low) / 2;
        }
        return -1;
    }
};
int main() {
    Solution sol_obj = Solution();
    std::vector<int> input = {1, 2, 3, 4, 5};
    int target = 4;
    int result = sol_obj.search(input, target);
    std::cout << "Target found at index " << result << "\n";
    return 0;
}