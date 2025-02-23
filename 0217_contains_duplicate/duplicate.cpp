#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> num_set;
        for (auto i : nums) {
            if (num_set.find(i) != num_set.end()) {
                return true;
            }
            num_set.insert(i);
        }
        return false;
    }
};

//testing code
int main() {
    Solution sol;
    vector<int> nums = {1, 4, 2, 11, 3, 1};
    cout << std::boolalpha << sol.containsDuplicate(nums) << endl;
    return 0;
}