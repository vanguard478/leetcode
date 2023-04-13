#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto itr_zero= nums.begin();
        auto itr = itr_zero;

        while(itr_zero!= )
    }
};

// main function for testing the code
int main() {
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}