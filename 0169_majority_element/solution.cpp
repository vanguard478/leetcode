#include<iostream>
#include<vector>
using namespace std;
class Solution{

public:
    int majorityElement(vector<int>& nums) {
        int count{0};
        int ele{0};
        for (int i {0};i < nums.size(); ++i){
            if ( count == 0){
                ++count;
                ele = nums[i];
            }
            else if ( nums[i]== ele){
                ++count;
            }
            else {
                --count;
            }
        }
        count = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] == ele) {
                count++;
            }
        }
        if (count > nums.size()/2)
            return ele;
        return -1;
    }
};


int main() {
    Solution sol;
    // Test case 1: Majority element is 2
    std::vector<int> nums1 = {2, 2, 1, 1, 1, 2, 2};
    std::cout << "Test case 1: " << sol.majorityElement(nums1) << std::endl;

    // Test case 2: Majority element is 3
    std::vector<int> nums2 = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    std::cout << "Test case 2: " << sol.majorityElement(nums2) << std::endl;

    // Test case 3: Majority element is 1
    std::vector<int> nums3 = {1, 1, 1, 2, 2, 3, 3, 3, 3};
    std::cout << "Test case 3: " << sol.majorityElement(nums3) << std::endl;

    return 0;

}