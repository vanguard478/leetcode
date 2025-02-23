#include<vector>
#include<iostream>
using namespace std;
/*
Compare two elements from the two array, check which is the smallest
and push it to the result vector.
1. We need to ensure that out of range doesnt occur in the loop so we 
have the while loop condition as i<m || j< n
2. If the first array is not exhausted and the second array is exhausted or 
the element in the first array is smaller than the element in the second array
then push the element from the first array to the result vector
3. If the second array is not exhausted and given the earlier if is false, 
then push the element from the second array to the result vector.

If nums1[i] is smaller or nums2 is exhausted, take from nums1.
Otherwise, if nums2 still has elements (j < n), take from nums2. 
This includes the case where nums1[i] is greater than nums2[j].

 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std:vector<int> result(m+n,0);
        int i =0,j=0,k=0;
        while (i<m || j< n){

            if ((i< m) && ( j>= n || (nums1[i] <= nums2[j]))){
                result[k] = nums1[i];
                i++;
                k++;
            }
            else if (j< n) {
                result[k] = nums2[j];
                j++;
                k++;
            }
        }
        nums1 = result;
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