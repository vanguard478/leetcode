#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int cur_area = 0, max_area = 0, min_hidx;

        int vsize = height.size();
        for (int i = 0, j = vsize - 1; i < j;) {
            min_hidx = height[i] <= height[j] ? i : j;
            cur_area = (j - i) * height[min_hidx];
            height[i] >= height[j] ? --j : ++i;
            max_area = max(cur_area, max_area);
        }

        return max_area;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solution.maxArea(height) << endl;
    return 0;
}