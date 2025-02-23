// [153. Find Minimum in Rotated Sorted Array]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left) / 2; 
        //still no return for a sorted array. if sorted array is input, 
        // the pivot will end up at the last element of the array.
        while (left != right) {
            if (nums[mid] >= nums[0]) {  //incorrect update for the right half selection
            //Failing for [2,1]
                left = mid;
            } else if (nums[mid] <= nums[right]) {
                right = mid;
            }
            mid = left + (right - left) / 2;
        }
        return mid;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,1};
    int minNum = sol.findMin(nums);
    cout << "Minimum number: " << minNum << endl;
    return 0;
}