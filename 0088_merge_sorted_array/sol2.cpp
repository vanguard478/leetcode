#include<vector>
#include<iostream>
using namespace std;
/*


 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last{m+n-1};
        while (m > 0 || n > 0){
            if ( (m > 0) && (n <= 0 || nums1[m-1] > nums2[n-1])){
                nums1[last]= nums1[m-1];
                --m;                
            }
            else if ( n > 0){
                nums1[last]= nums2[n-1];
                --n;
            }
            --last;

        }

        
    }
};


// Path: 88_merge_sorted_array/sol1.cpp
// Main function to test the solution
int main() {
    Solution sol;
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {2,5,6};
    sol.merge(nums1,3,nums2,3);
    for (auto i: nums1){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}