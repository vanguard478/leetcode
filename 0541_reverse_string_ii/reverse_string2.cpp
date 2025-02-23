#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * @brief Whether to use size_t or signed int for indices. Here we are
 * decrementing the indices also, the issue is caused by `j` being decremented
 * to the largest possible value of `size_t`. Since `size_t` is an unsigned
 * type, decrementing 0 will wrap around to the maximum value, causing undefined
 *  behavior.

To fix the issue, you can change the type of `i` and `j` to `int` or another
signed integer type. Also, you'll need to update the `min` function call to
 cast `s.length() - 1` to an `int` to avoid any type conflicts.

*
 */
class Solution {
public:
  string reverseStr(string s, int k) {
    // size_t start = 0;

    for (int start = 0; start < s.length(); start += 2 * k) {
      int i = start, j = min(start + k - 1, static_cast<int>(s.length() - 1));
      while (i <= j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
      }
      std::cout << "The current string status after 2k is :\n";
      for (auto i : s) {
        std::cout << i << " ";
      }
      std::cout << endl;
    }
    return s;
  }
};

// main function to test the code
int main() {
  Solution sol;
  string s = "ba";
  int k = 1;
  cout << sol.reverseStr(s, k) << endl;
  return 0;
}