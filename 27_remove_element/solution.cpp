#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        for(; i < nums.size(); ++i){
            if(nums[i]!=val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main() {
    // Test the code
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    
    Solution sol;
    int result = sol.removeElement(nums, val);
    
    cout << "Result: " << result << endl;
    
    return 0;
}
