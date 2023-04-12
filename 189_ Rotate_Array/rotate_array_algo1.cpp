// Rotate_array _leetcode
// https://leetcode.com/problems/rotate-array/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int start = 0, count = 0, size = nums.size();

        while (count < size) {
            int current = start, prev = nums[current];

            do {
                int next_idx = (current + k) % size;
                int temp = nums[next_idx];
                nums[next_idx] = prev;
                prev = temp;
                current = next_idx;
                count++;

            } while (current != start);
            start++;
        }
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