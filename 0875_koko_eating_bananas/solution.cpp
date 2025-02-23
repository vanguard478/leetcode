#include <algorithm>
#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // max of the piles value will give an upper-bound to the eating rate
        // at which Koko is bound to finish eating the bananas.
        
        auto max_iter = std::max_element(piles.begin(), piles.end());
        int initial_speed = 1;  // min value of piles[i] given in the constraint
        if (max_iter != piles.end()) {
            initial_speed = *max_iter;
        }
        int min_speed = initial_speed;

        int right = initial_speed;
        int left = 1;
        while (left != right) {
            int mid = left + (right - left) / 2;
            int total_hours{0};
            for (int i = 0; i < piles.size(); ++i) {
                // total_hours += std::ceil(static_cast<double>(piles[i]) / mid);
                total_hours += std::ceil(piles[i] / mid);

            }
            if (total_hours <= h) {
                min_speed = min(min_speed, mid);
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int minEatingSpeed = solution.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << minEatingSpeed << endl;
    return 0;
}