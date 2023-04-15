#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string reverseWords(string& s) {
    std::istringstream iss(s);
    std::string word, result;
    while (iss >> word) {
      std::reverse(word.begin(), word.end());
      result = result + word + " ";
    }
    if (!result.empty()) {
      result.pop_back();
    }
    return result;
  }
};

// main function for testing the code
int main() {
  Solution sol;
  string s = "Let's take LeetCode contest";
  cout << sol.reverseWords(s) << endl;
  return 0;
}