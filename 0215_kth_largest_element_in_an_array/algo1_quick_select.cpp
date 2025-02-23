#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int partition(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return low;
        }
        // Generate a random number between low and high (inclusive)
        int randomIndex = low + rand() % (high - low + 1);

        // Swap the randomly selected element with the last element (high)
        std::swap(nums[randomIndex], nums[high]);
        int i = low - 1, j = high, pivot = nums[high];

        while (true) {
            //keep on incrementing i untill an element greater than or equal to
            //pivot is found. The highest i can go is untill (high-1) i.e. one
            //before the pivot as pivot is set to nums[high]
            while (nums[++i] < pivot)
                ;
            //keep on decrementing j until an element smaller than or equal to
            //pivot is found. The lowest j can go is till low
            while (nums[--j] > pivot) {
                if (j == low) {
                    break;
                }
            }
            //Stop the scanning and break when i crosses over j
            if (i >= j) {
                break;
            }
            //swap the lesser element to the left and higher element to the right
            std::swap(nums[i], nums[j]);
        }
        //swap the pivot element to its correct position in the array, where
        //all elements on the left of the pivot are less than or equal to it
        //and all elements on the right of the pivot are greater than equal to it
        std::swap(nums[i], nums[high]);
        return i;
    }

    int quickSelect(vector<int>& nums, int low, int high, int k) {
        int partitionIdx = partition(nums, low, high);

        if (k == partitionIdx) {
            return nums[k];
        } else if (k < partitionIdx) {
            return quickSelect(nums, low, partitionIdx - 1, k);
        } else {
            return quickSelect(nums, partitionIdx + 1, high, k);
        }
    }
};

// Testing code for the above solution
int main() {
    srand(time(0));  // Seed the random number generator

    Solution sol;
    // std::vector<int> nums = {3, 1, 2, 2, 2, 1, 1, 5, 6, 6, 4};
    std::vector<int> nums = {1};

    int k = 1;
    std::cout << "The " << k << "th largest element is: " << sol.findKthLargest(nums, k) << std::endl;
    return 0;
}