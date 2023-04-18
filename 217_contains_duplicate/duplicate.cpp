#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (auto i : nums) {
            if (map.count(i) > 0) {
                return true;
            }
            map[i]++;
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