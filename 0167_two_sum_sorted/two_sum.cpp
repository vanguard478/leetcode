#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> index_map;
        std::vector<int> result(2);
        int size = numbers.size();
        int lookup;

        for (int i = 0; i < size; ++i) {
            lookup = target - numbers[i];
            auto itr = index_map.find(lookup);
            if (itr != index_map.end()) {
                return {index_map[lookup] + 1, i + 1};
            }
            index_map[numbers[i]] = i;
        }
        return result;
    }
};

// test code for the above function
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 4};
    int target = 6;
    vector<int> result = sol.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}