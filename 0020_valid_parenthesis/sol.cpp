#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
   public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            } else {
                if (stk.empty()){
                    return false;
                }
                char top = stk.top();
                stk.pop();
                if (
                    ch == ')' && top != '(' || ch == '}' && top != '{' || ch == ']' && top != '[') {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

// 20_valid_parenthesis
// driver code
int main() {
    Solution sol;
    string s = "()]{}";
    bool ans = sol.isValid(s);
    std::cout << std::boolalpha << ans << std::endl;
    return 0;
}