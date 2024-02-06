#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - min_price);
            }
        }

        return max_profit;
    }
};
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
