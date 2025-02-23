#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(result, "", 0, 0, n);
        return result;
    }

private:
void generateParenthesisHelper(vector<string>& result, string current, int openCount, int closeCount, int max, string indent = "") {
    cout << indent << "Current: " << current << ", Open: " << openCount << ", Close: " << closeCount << endl;

    if (current.length() == max * 2) {
        result.push_back(current);
        cout << indent << "Found: " << current << endl;
        return;
    }

    if (openCount < max) {
        generateParenthesisHelper(result, current + "(", openCount + 1, closeCount, max, indent + "  ");
    }

    if (closeCount < openCount) {
        generateParenthesisHelper(result, current + ")", openCount, closeCount + 1, max, indent + "  ");
    }

    cout << indent << "Backtrack from: " << current << endl;
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
