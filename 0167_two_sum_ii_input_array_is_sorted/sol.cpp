#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int vsize = numbers.size(), sum;

        for (int i = 0, j = vsize - 1; i <= j; ) {
            sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i, j};
            } else if (sum > target) {
                --j;
            } else {
                ++i;
            }
        }
        return {};
    }
};

//Testing Code
int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(numbers, target);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
} 