// Rotate_array _leetcode
// https://leetcode.com/problems/rotate-array/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[end];
            nums[end] = nums[start];
            nums[start] = temp;
            end--;
            start++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        reverse(nums,0,size-1);
        reverse(nums,k,size-1);
        reverse(nums,0,k-1);
    }
};

// Code for testing
int main() {
    Solution s;
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(vec, 3);
    for (auto i : vec) {
        cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}