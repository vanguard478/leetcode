#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    int start = 0, count = 0;
    while (count < n) {
        int current = start, prev = nums[start];
        std::cout << " The start is " << start << " for vector of size " << n
                  << " and shift " << k << endl;

        do {
            int next = (current + k) % n;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            // std::cout << "The arr at start= " << start
            //           << " and curr " << current
            //           << " and prev val " << prev
            //           << " and count " << count << endl;
            // for (auto i : nums) {
            //     std::cout << i << " ";
            // }
            // std::cout << endl;
            count++;
        } while (start != current);
        start++;
    }
}
// create a random vector of sorted integers between a and b and size n;
std::vector<int> random_vector(int n, int a, int b) {
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % (b - a + 1) + a;
    }
    sort(vec.begin(), vec.end());
    return vec;
}
int main() {
    int low = 1, high = 20;
    for (int i = 3; i < 20; i++) {
        std::vector<int> nums = random_vector(i, low, high);
        // std::cout << " *********** The vector is ***********" << endl;
        // for (auto i : nums) {
        //     cout << i << " ";
        // }
        int k;
        for (k = 2; k <= 9; k++) {
            std::cout << std::endl;
            rotate(nums, k);

            // for (int i = 0; i < nums.size(); i++) {
            //     cout << nums[i] << " ";
            // }
            // cout << endl;
        }
        // std::cout << "The size of array is  " << i << "and shift is " << k << endl;
        // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
        // int k = 2;
        // rotate(nums, k);

        // for (int i = 0; i < nums.size(); i++) {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
    }
    return 0;
}
