#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        auto itr_zero = nums.begin();
        auto itr = itr_zero;
        int temp;
        while (itr_zero != nums.end() && itr != nums.end()) {
            if (*itr_zero != 0) {
                itr_zero++;
                itr++;
                continue;
            }
            if (*itr == 0) {
                itr++;
                continue;
            }
            if (*itr_zero == 0 && *itr != 0) {
                *itr_zero = *itr;
                *itr = 0;
                itr_zero++;
                itr++;
            }
        }
    }
};

// main function for testing the code
int main() {
    Solution sol;
    vector<int> nums = {1};
    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}