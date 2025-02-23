#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;

        while (left <=right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                std::cout << "The values of in mid comparison left : " << left << " and right : " << right << endl;

                return mid;
            } else if (nums[mid] > target) {
                right = mid-1;
                std::cout << "The values of in Mid greater left : " << left << " and right : " << right << endl;
            } else {
                left = mid + 1;
                std::cout << "The values of in Mid less  left : " << left << " and right : " << right << endl;
            }
        }
        std::cout << "The values of left : " << left << " and right : " << right << endl;

        return left;
    }
};
// generate a random sorted array of length n
vector<int> randomSortedArray(int n) {
    vector<int> nums;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        nums.push_back(rand() % 100);
    }
    sort(nums.begin(), nums.end());
    return nums;
}

// main function for testing
int main() {
    Solution s;
    int size = 11;
    vector<int> nums = randomSortedArray(size);
    // std::vector<int> nums = {1, 3, 5, 6};
    
    // print nums array
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    std::cout << endl;
    // generate a random integer between 1 to 100 to be searched
    srand(time(NULL));
    int target = (rand() + rand()) % 100;
    // int target = 7;
    cout << "The target is " << target << endl;

    int pos = s.searchInsert(nums, target);
    cout << "position is " << pos << endl;
    // search for the target in the vector using STL
    auto orig_pos = find(nums.begin(), nums.end(), target) - nums.begin();
    std::cout << "The original position is " << orig_pos << endl;
    return 0;
}