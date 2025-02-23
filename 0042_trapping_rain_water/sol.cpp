#include <iostream>

#include <vector>

using namespace std;
class Solution {
   public:
    int trap(vector<int>& height) {
        int trapped_water = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int i=0;
        while(left<right) {

            int ghl = height[left], ghr = height[right];
            if (height[left] < height[right]) {
                int hl = height[left], hr = height[right];

                leftMax = max(leftMax, height[left]);
                trapped_water += leftMax - height[left];
                left++;

            } else {
                int hl = height[left], hr = height[right];

                rightMax = max(rightMax, height[right]);
                trapped_water += rightMax - height[right];
                right--;

            }
            i++;
        }
        return trapped_water;
    }
    
};

//driver code for trapping rain water
int main() {
    Solution sol;
    vector<int> height = {4,2,0,3,2,2};
    cout << sol.trap(height) << endl;
    return 0;
}