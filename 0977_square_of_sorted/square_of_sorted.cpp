#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0);
        int size = nums.size();
        int index = size-1;
        std::vector<int> vec(size);
        auto left = nums.begin(),right=prev(nums.end());
        for(int i= index;i>=0;--i){
            if(abs(*left)>=abs(*right)){
                vec[index--]= *left * *left;
                left++;
            }
            else{
                vec[index--]=*right * *right;
                right--;
            }
        }
        return vec;
    }
};

// main function for testing
// Create a random sorted vector of integers between a and b
// and print the result
std::vector<int> random_vector(int size, int a, int b) {
    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = rand() % (b - a + 1) + a;
    }
    sort(vec.begin(), vec.end());
    return vec;
}
int main() {
    Solution s;
    std::vector<int> vec = random_vector(5, -50, 100);
    for (auto i : vec) {
        cout << i << " ";
    }
    std::cout << std::endl;
    auto result = s.sortedSquares(vec);
    for (auto i : result) {
        cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}