#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    std::vector<string> result = {};
    generateParenthesisHelper(result, "", 0, 0, n);
    return result;
  }

private:
  void generateParenthesisHelper(vector<string> &result, string current,
                                 int openCount, int closedCount, int max) {
    if (current.length() == 2 * max) {
      result.push_back(current);
      return;
    }
    if (openCount < max) {
      generateParenthesisHelper(result, current + "(", openCount + 1,
                                closedCount, max);
    }
    if (closedCount < openCount) {
      generateParenthesisHelper(result, current + ")", openCount,
                                closedCount + 1, max);
    }
  }
};
// Driver code for testing
int main() {
    Solution sol;
    vector<string> result;
    int n = 3;
    result = sol.generateParenthesis(n);
    for (auto s : result) {
        cout << s << endl;
    }
    return 0;
}
