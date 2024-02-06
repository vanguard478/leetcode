#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                total_profit += prices[i] - prices[i - 1];
            }
        }
        return total_profit;
    }
    vector<pair<int, int>> findBuySellDays(vector<int>& prices) {
        vector<pair<int, int>> transactions;
        int n = prices.size();
        int i = 0;
        while (i < n - 1) {
            // Find the start of an upward trend
            while (i < n - 1 && prices[i + 1] <= prices[i]) {
                i++;
            }
            if (i == n - 1) break;
            int buy = i++;

            // Find the end of an upward trend
            while (i < n && prices[i] >= prices[i - 1]) {
                i++;
            }
            int sell = i - 1;

            transactions.push_back({buy, sell});
        }
        return transactions;
    }
};
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
        vector<pair<int, int>> transactions = sol.findBuySellDays(prices);

    cout << "Transactions: " << endl;
    for (auto &p : transactions) {
        cout << "Buy on day " << p.first << ", Sell on day " << p.second << endl;
    }
    return 0;
}
