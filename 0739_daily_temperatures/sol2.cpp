#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         vector<int> result(temperatures.size(), 0);
        stack<int> tempStack;  // Stack to store indices of temperatures
        
        for (int currentDay = 0; currentDay < temperatures.size(); ++currentDay) {
            while (!tempStack.empty() &&
                   temperatures[currentDay] > temperatures[tempStack.top()]) {
                int previousDay = tempStack.top();
                tempStack.pop();
                result[previousDay] = currentDay - previousDay;
            }
            tempStack.push(currentDay);
        }
        return result;
    }
};

// Main code for 739_daily_temperatures problem
int main() {
    Solution sol;
    // vector<int> temperatures = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
    // [8,1,5,4,3,2,1,1,0,0]

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    // [1,1,4,2,1,1,0,0]
    vector<int> result = sol.dailyTemperatures(temperatures);
    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}