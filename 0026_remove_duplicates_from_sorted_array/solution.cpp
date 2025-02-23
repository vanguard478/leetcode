#include <iostream>
#include <set>
#include <vector>
class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        int j{1};
        for (int i{1}; i < nums.size(); ++i) {
            if (nums[i - 1] != nums[i]) {
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};
// class Solution {
// public:
//     int removeDuplicates(std::vector<int>& nums) {
//         int j{0};
//         for (int i{0}; i < nums.size(); ++i) {
//             if (nums[i+1] != nums[i]) {
//                 nums[j]= nums[i];
//                 ++j;
//             }
//         }
//         return j;
//     }
// };
int main() {
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    Solution solution;
    std::cout << "the original nums is \n";
    for (auto i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    int length = solution.removeDuplicates(nums);
    std::set<int> uniqueSet(nums.begin(), nums.end());
    std::vector<int> uniqueVec(uniqueSet.begin(), uniqueSet.end());
    for (int num : uniqueVec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "the modified nums is \n";
    for (auto i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Length of array after removing duplicates: " << length << std::endl;
    return 0;
}
