#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string reverseWords(string &str) {
    int last_word_index = 0, str_size = str.length();

    for (int i = 0; i <= str_size; i++) {
      if (str[i] == ' ' || (i + 1) > str_size) {
        std::reverse(str.begin() + last_word_index, str.begin() + i);
        last_word_index = i + 1;
      }
    }
    return str;
  }
};

// main function for testing the code
int main() {
  Solution sol;
  string s = "Let's take LeetCode contest";
  cout << sol.reverseWords(s) << endl;
  return 0;
}