//Problem 347 Find the top k frequent element
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
     
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
    }
    void quickselect(vector<int>& nums, int left, int right, int k) {
        if (left >= right) return;
        int pivot_idx = parititon(nums, left, right);
        if (pivot_idx > k) {
            select(nums, left, pivot_idx - 1, k)
        }
        if ()
    }
    int parititon(vector<int>& nums, int left, int right) {
        int i = left - 1, j = right, pivot = nums[right];
        while (true) {
            while (nums[++i] < pivot)
                ;
            while (nums[--j] > pivot) {
                if (j == 1) {
                    break;
                }
            }
            if (i >= j) {
                swap(nums[i], nums[j]);
                break;
            }
        }
        swap(nums[i], pivot);
        return i;
    }
};

//testing code
int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = s.topKFrequent(nums, 2);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}