#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);  // Initialize all to 0
        for (int currentDay = 0; currentDay < temperatures.size(); ++currentDay) {
            for (int nextDay = currentDay + 1; nextDay < temperatures.size(); ++nextDay) {
                if (temperatures[nextDay] > temperatures[currentDay]) {
                    result[currentDay] = nextDay - currentDay;
                    break;  // Break as soon as a warmer day is found
                }
            }
        }
        return result;
    }
};


// Main code for 739_daily_temperatures problem
int main() {
    Solution sol;
    vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};
// [8,1,5,4,3,2,1,1,0,0]
    vector<int> result = sol.dailyTemperatures(temperatures);
    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}