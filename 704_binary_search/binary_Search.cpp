#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size() - 1,mid;
 
        while(low<=high){
            mid = low + (high-low)/2;

            if (nums[mid]== target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else
                low = mid+1; 
        }
        return -1;
    }

};



//main function for testing
int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;
    cout << s.search(nums, target) << endl;
    return 0;
}