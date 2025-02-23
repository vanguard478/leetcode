#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        auto zero_itr = nums.begin();
        auto pos_itr = zero_itr;
        int temp;
        while (pos_itr != nums.end()) {
            /*
            The zero_ptr and pos_ptr moves along through non-zero elements,
            if a zero is encountered zero_ptr stay at the same place and only
            the pos_ptr is moved ahead. Now the next non-zero element will
            get replaced the moment the pos_ptr points to it. And as the
            zero_ptr was pointing to the last zero encountered, the values will
            be swapped and the zero will move to the pos_itr position.
            */

            if (*pos_itr != 0) {
                int temp = *zero_itr;
                *zero_itr = *pos_itr;
                *pos_itr = temp;

                zero_itr++;
            }
            pos_itr++;


        }
    }
};

// main function for testing the code
int main() {
    Solution sol;
    vector<int> nums = {1, 4, 0, 5, 0, 2};
    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}