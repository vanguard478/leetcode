#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
void draw_pointers(const std::string &str, int left_idx, int right_idx) {
  std::string left_pointer = "L";
  std::string right_pointer = "R";

  // Print array elements
  for (int i = 0; i < str.size(); ++i) {
    std::cout << str[i] << ' ';
  }
  std::cout << '\n';

  // Draw pointers below the array
  for (int i = 0; i < str.size(); ++i) {
    if (i == left_idx && i == right_idx) {
      std::cout << 'B'; // Both pointers at the same position
    } else if (i == left_idx) {
      std::cout << left_pointer;
    } else if (i == right_idx) {
      std::cout << right_pointer;
    } else {
      std::cout << ' ';
    }
    std::cout << ' ';
  }
  std::cout << '\n';
}

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> chars;

    int left = 0;
    int right = 0;

    int res = 0;
    while (right < s.length()) {
      char r = s[right];
      chars[r]++;
      std::cout << "**Entry** :\n";
      draw_pointers(s, left, right);

      while (chars[r] > 1) {
        char l = s[left];
        chars[l]--;
        left++;
        std::cout << "**mid**** :\n";

        draw_pointers(s, left, right);
      }

      res = max(res, right - left + 1);

      right++;
      std::cout << "**Exit*** :\n";
      draw_pointers(s, left, right);
    }

    return res;
  }
};

// main code for testing
int main() {
  Solution sol;
  string s = "abcabcbb";
  int result = sol.lengthOfLongestSubstring(s);
  cout << result << endl;
  return 0;
}